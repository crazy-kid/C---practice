// workermi.h  -- working classes with MI
#ifndef WORKER_H_
#define WORKER_H_

#include <string>

class Worker   // an abstract base class
{
private:
    std::string fullname;
    long id;
protected:
    void Data() const;
    void Get();
public:
    Worker() : fullname("no one"), id(0L) {}
    Worker(const std::string& s, long n) : fullname(s), id(n) {}
    virtual ~Worker() {};
    void Set();
    void Show() const;
};

#endif
