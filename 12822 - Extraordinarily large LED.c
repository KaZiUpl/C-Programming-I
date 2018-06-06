#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define FOR(i,a,b) for(i=a;i<b;++i)
#define FORd(i,a,b) for(i=a;i>b;--i)
#define FOReq(i,a,b) for(i=a;i<=b;++i)
#define FORdeq(i,a,b) for(i=a;i>=b;--i)
#define print printf
#define scan scanf

int drain_values[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int power_drain(int number)
{
    if(number == 0) return drain_values[0];
    int drain=0;
    do
    {
        drain += drain_values[number%10];
        number = number/10;
    }while(number > 0);
    return drain;
}

int change_to_seconds(int hour,int minutes, int seconds) {return hour*3600+minutes*60+seconds;}

int main(void)
{
    int home=0,guest=0, points,case_number = 1;
    int hour,minutes,seconds,current_time,last_time;
    int power;
    char command[10];

    while(scan("%*s") == 0)
    {
        scan("%d:%d:%d",&hour,&minutes,&seconds);
        power = 0;
        home = 0,guest = 0;
        last_time = change_to_seconds(hour,minutes,seconds);

        while(scan("%s",command) == 1)
        {
            scan("%d:%d:%d",&hour,&minutes,&seconds);

            current_time = change_to_seconds(hour,minutes,seconds);
            power += (current_time - last_time) * (power_drain(home) + power_drain(guest));

            if(command[0] == 'E') break;
            else
            {
                scan("%s %d",command,&points);
                if(command[0] == 'h') home += points;
                else guest += points;
                last_time = current_time;
            }
        }
        print("Case %d: %d\n",case_number++,power);
    }
    return 0;
}
