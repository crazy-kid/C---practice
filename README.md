# C++-practice

- [C++-practice](#c-practice)
  - [数组](#数组)
  - [函数](#函数)
    - [参数传递与返回](#参数传递与返回)
    - [重载](#重载)
  - [指针与引用](#指针与引用)
    - [右值引用](#右值引用)
    - [智能指针](#智能指针)
  - [内存模型和名称空间](#内存模型和名称空间)
  - [类](#类)
    - [`this`指针](#this指针)
    - [构造函数](#构造函数)
    - [初始化](#初始化)
  - [继承与多态](#继承与多态)
    - [继承](#继承)
    - [多重继承](#多重继承)
    - [虚函数](#虚函数)
  - [多进程与多线程](#多进程与多线程)
  - [编程习惯](#编程习惯)
  - [环境配置](#环境配置)
    - [常见变量说明](#常见变量说明)
    - [编译配置](#编译配置)
    - [运行配置](#运行配置)
      - [常用条目](#常用条目)
    - [GDB调试](#gdb调试)
    - [valgrind](#valgrind)

## 数组

1. 数组名作为实参被传入函数时在函数内部只是相应的指针

   **example**

   ```cpp
   int main(int argc, char const* argv[])
   {
      char arr[5];
      strcpy(arr, "helloWorld");
      cout << "strlen: " << strlen(arr) << endl; // 10 结果只和内存中的值有关与数组无关
      cout << "sizeof: " << sizeof(arr) << endl; // 5 sizeof是预编译指令，作用在数组名上得到整个数组占内存的字节数
      fun_char(arr);

      int arr2[] = { 1,2,3,4,5 };
      cout << "sizeof: " << sizeof(arr2) << endl; // 20 每个int占4字节，数组大小为5，4 * 5 = 20
      fun_int(arr2);
      return 0;
   }

   void fun_char(char arr[]) // 看起来arr是个数组，其实是个指针
   {
      cout << "arr type: " << typeid(arr).name() << endl; // Pc: 指向char的指针
      cout << "strlen: " << strlen(arr) << endl; // 10 理由同上
      cout << "sizeof: " << sizeof(arr) << endl; // 8 函数内的arr不是数组名，只是指针。sizeof 最后返回的是一个内存地址占的字节数，64位系统是8个字节
   }

   void fun_int(int arr[])
   {
      cout << "arr type: " << typeid(arr).name() << endl; // Pi: 指向int的指针
      cout << "sizeof: " << sizeof(arr) << endl; // 8 理由同上
   }
   ```

## 函数

### 参数传递与返回

1. 不要返回局部变量的引用，因为对应的内存将在函数结束后被销毁，这将造成引用不存在内存的错误
2. 非引用的函数返回值只能作为**右值**，但返回引用的函数可以作为**左值**，要避免这种特性需要在返回值前加上`const`
3. `const`量是无法作为实参传递给非`const`引用形参的但是反过来是可以的:非`const`量可以作为实参传递给`const`引用

    **example**

   ```cpp
    int& f1(int& a);
    const int& f2(int& a);
    int f3(int& a);

    int main() {
        int num1 = 1, num2 = 2;
        const int num3 = 3;
        f1(num1) = 5; // NOTE2:可以通过编译，语句执行后num1==5
        f2(num2) = 9; // NOTE2:无法通过编译，f2(num2)无法作为左值
        f1(num3); // NOTE3:无法通过编译
    }

    int& f1(int& a) {
        a++;
        return a;
    }

    const int& f2(int& a) {
        a++;
        return a;
    }

    int f3(int& a) {
        return a++;
    }
   ```

### 重载

1. 函数**重载**时，C++将区分常量和非常量函数的**特征标**

## 指针与引用

1. 左值是能够被`&`取内存地址的表达式，除了左值都是右值
2. 从生成的汇编来看函数传递引用和传递指针没有区别,因此

      |引用                          | 指针                    |
      |------------------------------|------------------------|
      |非常量左值引用只能绑定非常量左值  |  非`const`指针不能指向常量|
      |常量左值引用可以绑定非常量左值、常量左值、右值 | `const`指针也能够指向非常量 |
3. 指针和引用的区别

   - **是否占用内存** 指针占用内存，引用不占用
   - **是否可变** 引用指向的内存地址不可变，指针指向的内存地址在运行过程中可变
4. `cout`输出`char*`会把整个字符串打出来，若要打印地址需要做强制转换 `(void *)`

### 右值引用

1. 右值引用的用法
   1. 移动语义：通过移动构造函数实现
   2. 完美转发：通过模板函数和`std::forward()`实现

### 智能指针

1. 对象应该在创建的同时就赋值给智能指针，下面的代码是危险的，应该使用`make_shared<T>`
   **example**

   ```cpp
   Dog* d = new Dog("Tank"); // bad idea
   shared_ptr<Dog> p1(d); // p1.use_count() == 1
   shared_ptr<Dog> p2(d); // p2.use_count() == 1
   ```

## 内存模型和名称空间

1. 定义类的成员函数时需要用到作用域解析运算符`::`
2. `using`声明使特定的标识符可用，`using namespace`编译指令使整个名称空间可用

## 类

### `this`指针

1. `this`指针不占用类的大小，即计算`sizeof(class)`时不会考虑`this`指针
2. 编译器在编译时会把`this`指针作为参数添加进成员函数（包括定义和调用）

### 构造函数

1. 一个强壮的`class`中至少应该有
   1. **默认构造函数**:（也能用带默认参数的构造函数替代）
   2. **复制构造函数**:以下情况将调用
      - `TypeName newObject = TypeName(object)`
      - `TypeName newObject = object`
      - 函数按值传入或返回对象
   3. **默认析构函数**
   4. **赋值运算符**:（处理`object1 = object2`，需要实现深度复制）
   5. **地址运算符**:（通常不用特别处理）
2. 将派生类对象赋值给基类对象时调用的是基类对象的赋值构造函数

### 初始化

1. 使用**初始化列表**时，项目被初始化的顺序是它们被声明的顺序而不是初始化列表中的顺序
2. `const`类成员的初始化可以用2种方式初始化:
   1. 构造函数的**初始化列表语法**完成
   2. 类内初始化，但这样只能使用默认值

## 继承与多态

1. **多态**，即同一个方法的行为随上下文而异

### 继承

1. C++有3种继承方式:
   1. **公有继承**: `public`->`public`;  `protect`->`protect`
   2. **保护继承**: `public`&`protect`->`protect`
   3. **私有继承**: `public`&`protect`->`private`
2. 派生类构造函数执行顺序
   1. 创建基类对象
   2. 通过成员初始化列表将基类信息传递给基类构造函数,否则将使用默认的基类构造函数
   3. 初始化派生类新增的数据成员
3. 派生对象过期时，程序将首先调用派生类析构函数，然后在调用基类析构函数
4. 派生类函数调用基类函数时必须使用作用域解析符`::`
5. **包含**与**私有继承**的区别
   1. 包含提供被显式命名的对象成员，私有继承提供无名称的子对象成员
   2. 对于继承类，构造函数使用成员初始化列表语法，它使用类名而不是成员名来标识构造函数
   3. 使用包含时通过对象名调用方法，私有继承使用类名和+作用域运算符

### 多重继承

1. 使用多个基类的继承被称为**多重继承**（multiple inheriance, MI）
2. 多重继承的主要问题是
   1. 从多个不同的基类继承同名方法(使用模块化的思想设计基类或者将所有的数据控制组件设为`protect`)
   2. 从多个不同的基类中继承同一个祖先类的多个实例(可以使用**虚基类**解决)
3. 如果类有间接虚基类，要显式地调用该虚基类的某个构造函数，除非需要的是默认构造
4. 当类通过多条虚途径继承某个特定的基类时，该类将包含一个表示所有虚途径的基类子对象和分别表示各条非虚途径的多个基类子对象

### 虚函数

1. 实现多态公有继承的两种重要机制
   1. 在派生类中重新定义基类方法
   2. 使用**虚方法**
2. 如果没有使用关键字`virtual`，程序将根据引用类型或者指针类型选择方法；如果使用了`virtual`，程序将根须引用或者指针指向的对象的类型来选择方法
3. 方法在基类中被声明为`virtual`后，它在派生类中将自动成为`virtual`方法
4. **函数名联编**有两种:
   1. **静态联编**（早期联编）:在程序编译时就能决定调用函数对应的代码块
   2. **动态联编**（晚期联编）:在程序运行时才能决定调用函数对应的代码块
5. 编译器对虚方法使用动态联编
6. 按值传递会导致派生类的对象只把基类的部分传递给虚函数，下面的例子中`BrassPlus`是`Brass`的公有派生类，`ViewAcct()`是虚函数

    **example**

    ```cpp
    void fr(Brass& rb); // uses rb.ViewAcct()
    void fp(Brass* pb); // uses pb->ViewAcct()
    void fv(Brass  b);  // uses b.ViewAcct()

    int main() {
        Brass b("Billy Bee", 123432, 10000.0);
        BrassPlus bp("Betty Beep", 232313, 12345.0);
        fr(b);  //uses Brass::ViewAcct()
        fr(bp); //uses BrassPlue::ViewAcct()
        fp(b);  //uses Brass::ViewAcct()
        fp(bp); //uses BrassPlue::ViewAcct()
        fv(b);  //uses Brass::ViewAcct()
        fv(bp); //uses Brass::ViewAcct()
    }
    ```

7. 编译器处理虚函数的方法:给每个对象添加一个隐藏成员。隐藏成员中保存了一个指向函数地址数组的指针。这种数组称为**虚函数表**。虚函数表中存储了为类对象进行声明的虚函数地址
8. 使用虚函数时，对于每一个类，编译器都创建一个虚函数地址表（数组），每一个对象都创建一个指针
9. `virtual`在函数名和参数列表相同的情况下可以被派生类继承：派生类中的函数就算没有`virtual`修饰，只要基类中有相同函数名、参数列表的`virtual`函数，派生类中的函数也视为被`virtual`修饰
10. 任何类只要自身有成员函数是虚函数（被隐藏的`virtual`函数也包括），该类的对象里就有指向虚函表的指针

      **example**

      ```cpp
      class Base
      {
         long x;
      public:
         virtual void show() { cout << "x = " << x << endl; }
      };

      class A : public Base
      {
         long y;
      public:
         virtual void show() { cout << "y = " << y << endl; }
      };

      class B {
         int z;
         char c;
      public:
         void show() { cout << "y = " << z << endl; }
      };

      int main(int argc, char const* argv[])
      {
         // sizeof 需要考虑内存对齐
         // 16 8(x) + 8(Vptr)
         cout << "sizeof(Base) = " << sizeof(Base) << endl;
         // 24 8(Base::x) + 8(y) + 8(Vptr)
         cout << "sizeof(A) = " << sizeof(A) << endl;
         // 8 4(z) + 1(c) + 3(内存对齐)
         // B没有虚方法，也没有基类，如果将B::shwo()声明为virtual则会变为16
         cout << "sizeof(B) = " << sizeof(B) << endl;
         return 0;
      }
      ```

11. 同样名称的虚函数，在基类中定义的虚函数与派生类中定义的虚函数，在虚函数表中的偏移量都是一致的，只有这样才能保证动态绑定
12. 构造函数不能是虚函数；析构函数应该是虚函数，除非类不用做基类；友元不能是虚函数，因为友元不是类成员
13. **函数重写（覆盖）** 必须满足如下条件
    - 函数名、参数列表、返回值都必须与基类中被重写的函数一致
    - 基类中被重写的函数必须有`virtual`修饰
14. **函数隐藏** 指派生类的函数屏蔽了有相同函数名的函数（无论参数列表是否相同都会屏蔽）
15. 隐藏发生在编译时，重写发生在运行时；隐藏根据指针类型调用函数，重写根据虚函数表调用函数

## 多进程与多线程

1. `join()`会阻塞当前线程直到子线程结束，若在该函数执行前子线程就结束了则不会阻塞当前线程
2. `detach()`会将当前线程与子线程“分离”，即主线程结束后子线程仍然可以运行
3. `fork()`将创建一个子进程，子进程将复制父进程的内存空间，创建失败返回-1,创建成功时父进程返回子进程的`pid`，子进程返回0

## 编程习惯

1. 使用`typedef`能够有效地简化复杂结构的声明
2. 无法立刻提供复制构造函数和赋值运算符时可以采取**伪私有方法**防止程序崩溃
3. 如果要在派生类中重新定义基类的方法，则将它设置为虚方法；否则设置为非虚方法
4. 通常应给基类提供一个**虚析构函数**，即使它并不需要析构函数
5. **重新定义**的两条经验规则
   1. **返回类型协变**: 如果重新定义继承的方法，应确保与原来的原型完全相同，但如果返回类型是基类引用或指针，则可以修改为指向派生类的引用或指针
   2. 如果基类声明被重载了，则应在派生类中重新定义所有的基类版本

## 环境配置

### 常见变量说明

- `${workspaceRoot}`: VSCode中打开文件夹的路径
- `${workspaceRootFolderName}`: VSCode中打开文件夹的路径, 但不包含"/"
- `${workspaceFolder}`: 在Visual Studio Code中打开的文件夹的完整路径
- `${workspaceFolderBasename}`: 在Visual Studio Code中打开的文件夹名
- `${file}`: 当前打开的文件的完整路径
- `${relativeFile}`:当前打开的文件的相对workspaceFolder路径
- `${relativeFileDirname}`: 当前打开的文件的文件夹的相对workspaceFolder路径
- `${fileBasenameNoExtension}`: 当前打开的文件的文件名，不包含扩展名
- `${fileDirname}`: 当前打开的文件的文件夹的完整路径
- `${fileExtname}`: 当前打开的文件的扩展名
- `${cwd}`: Task启动时的工作目录
- `${lineNumber}`: 当前光标的所在的行号
- `${selectedText}`: 当前打开的文件中选中的文本
- `${execPath}`: Visual Studio Code可知行文件的完整路径
- `${defaultBuildTask}`: 默认的Build Task的名字
- `${env:Name}`: 引用环境变量
- `${config:Name}`: 可以引用Visual Studio Code的设置项
- `${input:variableID}`: 传入输入变量

### 编译配置

VScode使用`.vscode`中的`task.json`文件配置编译信息

1. 多文件编译时需要将`"args"`里的`-g`参q数`"${file}"`更改为`"*.cpp"`，`-g`意思是添加调试参数
2. 在Linux下应当使用g++编译cpp文件而不是gcc,因为gcc似乎不会自动链接库

### 运行配置

VScode使用`.vscode`中的`lunch.json`文件配置运行信息

#### 常用条目

1. `preLaunchTask`: 在launch之前运行的任务名，要与`task.json`中的`label`保持一致
2. `program`: 可执行文件的路径
3. `stopAtEntry`: 选为true则会在打开控制台后停滞，暂时不执行程序
4. `cwd`: 当前工作路径，即程序启动时控制台所在路径
5. `miDebuggerPath`: 调试器路径，通常是`gdb`

### GDB调试

1. 对于交叉编译的文件，有时需要使用`file ${file}`来加载符号
2. Linux下程序崩溃时会在指定目录下生成`.core`文件，其中包含内存映像和调试信息，gdb可以调试`.core`文件，如果没有生成`.core`文件，可能是`ulimit`设置不对

### valgrind

仿真调试工具集合
