#include <iostream>
using namespace std;
class x {
    private:
        int hour,min,sec;
    public:
        x(int h=0,int m=0,int s=0):hour(h),min(m),sec(s){}
        x add(const x &t){
            x t3;
            t3.hour=hour+t.hour;
            t3.min=min+t.min;
            t3.sec=sec+t.sec;
            if (t3.sec>=60) {
                t3.min++;
                t3.sec-=60;
            }
            if (t3.min>=60) {
                t3.hour++;
                t3.min-=60;
            }
            return t3;

        }
        x subtract(const x &t) {
            x t2(hour,min,sec);
            x t1=t;
            t2.min+=t2.sec/60;
            t2.sec%=60;
            t2.hour+=t2.min/60;
            t2.min%=60;
            t1.min+=t1.sec/60;;
            t1.sec%=60;
            t1.hour+=t1.min/60;
            t1.min%=60;
            if (t2.hour<t1.hour || (t2.hour==t1.hour && t2.min<t1.min) || (t2.hour==t1.hour && t2.min==t1.min && t2.sec<t1.sec)) {
                cout<<"Cannot subtract a larger x from a smaller x."<<endl;
                return x(0,0,0);
            }
            if (t2.sec<t1.sec) {
                t2.min--;
                t2.sec+=60;
            }
            if (t2.min<t1.min) {
                t2.hour--;
                t2.min+=60;
            }
            t2.sec-=t1.sec;
            t2.min-=t1.min;
            t2.hour-=t1.hour;
            return x(t2.hour,t2.min,t2.sec);
        }
        void display() const{
            cout<<hour<<":"<<min<<":"<<sec<<endl;
        }
    };
int main() {
    x ct1(4,61,71),c2(2,9,2);
    x sum=ct1.add(c2);
    x diff=ct1.subtract(c2);
    cout<<"First x : ";
    ct1.display(); cout<<"Second x : ";
    c2.display(); cout<<"Addition: ";
    sum.display(); cout<<"Subtraction: ";
    diff.display();
    return 0;
}