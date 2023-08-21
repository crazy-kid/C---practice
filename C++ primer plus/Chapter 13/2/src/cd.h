class Cd
{
private:
    char* performers;
    char* label;
    int selections;
    double playtime;

public:
    Cd(char* s1, char* s2, int n, double x);
    Cd(const Cd& d);
    Cd();
    ~Cd();
    virtual void Report() const;
    virtual Cd& operator=(const Cd& d);
};