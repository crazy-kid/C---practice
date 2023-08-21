#ifndef CLASSIC_H_
#define CLASSIC_H_

#include "cd.h"

class Classic :public Cd
{
private:
    char* works;

public:
    Classic(char* performers, char* label, char* works, int selections, double x);
    Classic(const Classic& cic);
    Classic();
    ~Classic();
    virtual void Report()const;
    virtual Classic& operator=(const Classic& cic);
};

#endif