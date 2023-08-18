# C++-practice

- [C++-practice](#c-practice)
  - [NOTE](#note)
  - [编程习惯](#编程习惯)


## NOTE
1. 从生成的汇编来看函数传递引用和传递指针没有区别
2. `cout`输出`char*`会把整个字符串打出来，若要打印地址需要做强制转换 `(void *)`
3. 定义类的成员函数时需要用到作用域解析运算符`::`
4. `using`声明使特定的标识符可用，`using namespace`编译指令使整个名称空间可用。
5. 非引用的函数返回值只能作为右值，但返回引用的函数可以作为左值，要避免这种特性需要在返回值前加上`const`

    **Example**
    ```C++
    int& f1(int& a);
    const int& f2(int& a);

    int main() {
        int num1 = 1, num2 = 2;
        f1(num1) = 5;//可以通过编译，语句执行后num==5。
        f2(num2) = 9;//无法通过编译，f2(num2)无法作为左值。
    }

    int& f1(int& a) {
        a++;
        return a;
    }

    const int& f2(int& a) {
        a++;
        return a;
    }    
    ```
   
## 编程习惯
1. 在Linux下应当使用g++编译cpp文件而不是gcc,因为gcc似乎不会自动链接库
2. 使用`typedef`能够有效地简化复杂结构的声明
3. 编写`.h`文件时通常用命名空间将其包裹起来。