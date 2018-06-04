#include<stdio.h>

#define FOR(i,a,b) for(i=a;i<b;++i)
#define FORd(i,a,b) for(i=a;i>b;--i)
#define FOReq(i,a,b) for(i=a;i<=b;++i)
#define FORdeq(i,a,b) for(i=a;i>=b;--i)
#define print printf
#define scan scanf

int main(void)
{
    int test_cases;
    int hour, minutes;
    int new_hour, new_minutes;
    scan("%d",&test_cases);
    while(test_cases--)
    {
        scan("%d:%d",&hour,&minutes);

        if(minutes == 0)
        {
                if(hour == 12) print("%d:00\n",hour);
                else
                {
                    new_hour = 12 - hour;
                    if(new_hour >= 10) print("%d:00\n",new_hour);
                    else print("0%d:00\n",new_hour);
                }
        }
        else
        {
            new_minutes = 60 - minutes;

            if(hour == 12) new_hour = 11;
            else if(hour == 11) new_hour = 12;
            else new_hour = 11 - hour;


            if(new_hour >= 10) print("%d:",new_hour);
            else print("0%d:",new_hour);

            if(new_minutes >= 10) print("%d\n",new_minutes);
            else print("0%d\n",new_minutes);
        }
    }


    return 0;
}
