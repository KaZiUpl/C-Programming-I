#include<stdio.h>

#define FOR(i,a,b) for(i=a;i<b;++i)
#define FORd(i,a,b) for(i=a;i>b;--i)
#define FOReq(i,a,b) for(i=a;i<=b;++i)
#define FORdeq(i,a,b) for(i=a;i>=b;--i)
#define print printf
#define scan scanf

int main(void)
{
    int how_many_players, match_points, match_point;
    int number_of_players = 0;
    int always_scored = 1;
    while(scan("%d %d",&how_many_players,&match_points) == 2)
    {
        int i,j;
        FOR(i,0,how_many_players)
        {
            always_scored = 1;
            FOR(j,0,match_points)
            {
                scan("%d",&match_point);
                if(match_point == 0) always_scored = 0;
            }
            if(always_scored) number_of_players++;
        }
        print("%d\n",number_of_players);
        number_of_players = 0;
    }


    return 0;
}
