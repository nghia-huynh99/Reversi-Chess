#include <iostream>
#include <vector>

using namespace std;

typedef struct point
{
    int x; // toa do hang
    int y; // toa do cot
} toa_do;

typedef vector<vector<int>> ban_co;

void print_ban_co(ban_co bc)
{
    int kich_thuoc = bc.size();
    cout << "  ";
    for (int i = 0; i < kich_thuoc; i++)
        cout << i << " ";
    for (int i = 0; i < kich_thuoc; i++)
    {
        cout << endl;
        cout << i << " ";
        for (int j = 0; j < kich_thuoc; j++)
        {
            if (bc[i][j] == 0)
                cout << "- ";
            else if (bc[i][j] == -1)
                cout << "X ";
            else
                cout << "O ";
        }
    }
    cout << endl;
}

ban_co init_ban_co(int _size) // size la so chan
{
    ban_co bc(_size, vector<int>(_size));
    int i = _size / 2 - 1;
    bc[i][i] = -1; bc[i][i + 1] = 1;
    bc[i + 1][i] = 1; bc[i + 1][i + 1] = -1;
    return bc;
}


vector<toa_do> generate_valid_moves(ban_co bc, int player)
{
        vector<toa_do> kq;
        int _size = bc.size();
        int opp = -1*player;

        //Kiem tra dong
        for (int i = 0; i < _size; i++)
        {
            for (int j = 2; j < _size; j++)
            {
                if((bc[i][j]==player)&&(bc[i][j-1]==opp))
                {
                    for( int k=j-2;k>=0;k--)
                    {
                        if(bc[i][k]==player)
                        {
                            break;
                        }
                        else if(bc[i][k]==0&&k>=0)
                        {
                        toa_do temp;
                        temp.x=i;
                        temp.y=k;
                        kq.push_back(temp);
                        break;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < _size; i++)
        {
            for (int j = 0; j < _size-2; j++)
            {
                if((bc[i][j]==player)&&(bc[i][j+1]==opp))
                {
                    for(int k=j+2;k<_size;k++)
                    {
                         if(bc[i][k]==player)
                        {
                            break;
                        }
                        else if(bc[i][k]==0&&k<_size)
                        {
                        toa_do temp;
                        temp.x=i;
                        temp.y=k;
                        kq.push_back(temp);
                        break;
                        }
                    }
                }
            }
        }

        //Kiem tra cot
        for (int i = 2; i < _size; i++)
        {
            for (int j = 0; j < _size; j++)
            {

                if((bc[i][j]==player)&&(bc[i-1][j]==opp))
                {
                    for( int k=i-2;k>=0;k--)
                    {
                         if(bc[k][j]==player)
                        {
                            break;
                        }
                        else if(bc[k][j]==0&&k>=0)
                        {
                        toa_do temp;
                        temp.x=k;
                        temp.y=j;
                        kq.push_back(temp);
                        break;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < _size-2; i++)
        {
            for (int j = 0; j < _size; j++)
            {
                if((bc[i][j]==player)&&(bc[i+1][j]==opp))
                {
                    for(int k=i+2;k<_size;k++)
                    {
                         if(bc[k][j]==player&&k<_size)
                        {
                            break;
                        }
                        else if(bc[k][j]==0)
                        {
                        toa_do temp;
                        temp.x=k;
                        temp.y=j;
                        kq.push_back(temp);
                        break;
                        }
                    }
                }
            }
        }

        //Kiem tra duong cheo phuong tay bac - dong nam
        for (int i = 2; i < _size; i++)
        {
            for (int j = 2; j < _size; j++)
            {
                if((bc[i][j]==player)&&(bc[i-1][j-1]==opp))
                {
                    int n=j-2;
                    for( int k=i-2;k>=0;k--)
                    {
                         if(bc[k][n]==player)
                        {
                            break;
                        }
                        else if(bc[k][n]==0&&k>=0&&n>=0)
                        {
                        toa_do temp;
                        temp.x=k;
                        temp.y=n;
                        kq.push_back(temp);
                        break;
                        }
                        n--;
                    }
                }
            }
        }
        for (int i = 0; i < _size-2; i++)
        {
            for (int j = 0; j < _size-2; j++)
            {
                if((bc[i][j]==player)&&(bc[i+1][j+1]==opp))
                {
                    int q=j+2;
                    for(int k=i+2;k<_size;k++)
                    {
                         if(bc[k][q]==player)
                        {
                            break;
                        }
                        else if(bc[k][q]==0&&k<_size&&q<_size)
                        {
                        toa_do temp;
                        temp.x=k;
                        temp.y=q;
                        kq.push_back(temp);
                        break;
                        }
                        q++;
                    }
                }
            }
        }

        //Kiem tra duong cheo phuong tay nam - dong bac
        for (int i = 2; i < _size; i++)
        {
            for (int j = 0; j < _size-2; j++)
            {
                if((bc[i][j]==player)&&(bc[i-1][j+1]==opp))
                {
                    int p=j+2;
                    for( int k=i-2;k>=0;k--)
                    {
                         if(bc[k][p]==player)
                        {
                            break;
                        }
                        else if(bc[k][p]==0&&k>=0&&p<_size)
                        {
                        toa_do temp;
                        temp.x=k;
                        temp.y=p;
                        kq.push_back(temp);
                        break;
                        }
                        p++;
                    }
                }
            }
        }
        for (int i = 0; i < _size-2; i++)
        {
            for (int j = 2; j < _size; j++)
            {
                if((bc[i][j]==player)&&(bc[i+1][j-1]==opp))
                {
                    int h=j-2;
                    for(int k=i+2;k<_size;k++)
                    {
                         if(bc[k][h]==player)
                        {
                            break;
                        }
                        else if(bc[k][h]==0&&k<_size&&h>=0)
                        {
                        toa_do temp;
                        temp.x=k;
                        temp.y=h;
                        kq.push_back(temp);
                        break;
                        }
                        h--;
                    }
                }
            }
        }
    return kq;
}

void play_moves(ban_co& bc, int player, toa_do vitri)
{
    int opp=-1*player;
    int _size = bc.size();
    if(vitri.x<0||vitri.x>_size-1||vitri.y<0||vitri.y>_size-1)
    {
       return;
    }
    else
    {
        int check=0;
        //west
        if(vitri.y>=2)
        {
        if((bc[vitri.x][vitri.y]==0)&&(bc[vitri.x][vitri.y-1]==opp))
        {
            for(int j=vitri.y-2;j>=0;j--)
            {
                if(bc[vitri.x][j]==0)
                {
                    break;
                }
                else if(bc[vitri.x][j]==player)
                {
                    check++;
                    for(int k=vitri.y-1;k>j;k--)
                    {
                        bc[vitri.x][k]=player;
                    }
                    break;
                }
            }
        }
        }

        //east
        if(vitri.y<_size-2)
        {
        if((bc[vitri.x][vitri.y]==0)&&(bc[vitri.x][vitri.y+1]==opp))
        {
            for(int j=vitri.y+2;j<_size;j++)
            {
                if(bc[vitri.x][j]==0)
                {
                    break;
                }
                else if(bc[vitri.x][j]==player)
                {
                    check++;
                    for(int k=vitri.y+1;k<j;k++)
                    {
                        bc[vitri.x][k]=player;
                    }
                    break;
                }
            }
        }
        }

        //north
        if(vitri.x>=2)
        {
        if((bc[vitri.x][vitri.y]==0)&&(bc[vitri.x-1][vitri.y]==opp))
        {
            for(int i=vitri.x-2;i>=0;i--)
            {
                if(bc[i][vitri.y]==0)
                {
                    break;
                }
                else if(bc[i][vitri.y]==player)
                {
                    check++;
                    for(int k=vitri.x-1;k>i;k--)
                    {
                        bc[k][vitri.y]=player;
                    }
                    break;
                }
            }
        }
        }

        //south
        if(vitri.x<_size-2)
        {
        if((bc[vitri.x][vitri.y]==0)&&(bc[vitri.x+1][vitri.y]==opp))
        {
            for(int i=vitri.x+2;i<_size;i++)
            {
                if(bc[i][vitri.y]==0)
                {
                    break;
                }
                else if(bc[i][vitri.y]==player)
                {
                    check++;
                    for(int k=vitri.x+1;k<i;k++)
                    {
                        bc[k][vitri.y]=player;
                    }
                    break;
                }
            }
        }
        }

        //north-west
        if(vitri.x>=2&&vitri.y>=2)
        {
        if((bc[vitri.x][vitri.y]==0)&&(bc[vitri.x-1][vitri.y-1]==opp))
        {
            int j=vitri.y-2;
            for(int i=vitri.x-2;i>=0;i--)
            {
                if(bc[i][j]==0)
                {
                    break;
                }
                else if(bc[i][j]==player&&j>=0)
                {
                    int h=vitri.y-1;
                    for(int k=vitri.x-1;k>i;k--)
                    {
                        check++;
                        if(h>j)
                        {
                            bc[k][h]=player;
                        }
                        h--;
                    }
                    break;
                }
                j--;
            }
        }
        }

        //south-east
        if((vitri.x<_size-2)&&(vitri.y<_size-2))
        {
        if((bc[vitri.x][vitri.y]==0)&&(bc[vitri.x+1][vitri.y+1]==opp))
        {
            int j=vitri.y+2;
            for(int i=vitri.x+2;i<_size;i++)
            {
                if(bc[i][j]==0)
                {
                    break;
                }
                else if(bc[i][j]==player&&j<_size)
                {
                    check++;
                    int h=vitri.y+1;
                    for(int k=vitri.x+1;k<i;k++)
                    {
                        if(h<j)
                        {
                            bc[k][h]=player;
                        }
                        h++;
                    }
                    break;
                }
                j++;
            }
        }
        }

        //north-east
        if((vitri.x>=2)&&(vitri.y<_size-2))
        {
        if((bc[vitri.x][vitri.y]==0)&&(bc[vitri.x-1][vitri.y+1]==opp))
        {
            int j=vitri.y+2;
            for(int i=vitri.x-2;i>=0;i--)
            {
                if(bc[i][j]==0)
                {
                    break;
                }
                else if(bc[i][j]==player&&j<_size)
                {
                    check++;
                    int h=vitri.y+1;
                    for(int k=vitri.x-1;k>i;k--)
                    {
                        if(h<j)
                        {
                            bc[k][h]=player;
                        }
                        h++;
                    }
                    break;
                }
                j++;
            }
        }
        }

        //south-west
        if((vitri.x<_size-2)&&(vitri.y>=2))
        {
        if((bc[vitri.x][vitri.y]==0)&&(bc[vitri.x+1][vitri.y-1]==opp))
        {
            int j=vitri.y-2;
            for(int i=vitri.x+2;i<_size;i++)
            {
                if(bc[i][j]==0)
                {
                    break;
                }
                else if(bc[i][j]==player&&j>=0)
                {
                    check++;
                    int h=vitri.y-1;
                    for(int k=vitri.x+1;k<i;k++)
                    {
                        if(h>j)
                        {
                            bc[k][h]=player;
                        }
                        h--;
                    }
                    break;
                }
                j--;
            }
        }
        }

        if(check>0)
        {
            bc[vitri.x][vitri.y]=player;
        }
        else
        {
            return;
        }
    }
}
int main()
{
    ban_co bc = init_ban_co(10);
    print_ban_co(bc);
    int player = -1;

    /*bc[0][5]=1;
    bc[1][1]=1;
    bc[1][2]=-1;
    bc[1][3]=-1;
    bc[1][4]=1;
    bc[1][5]=1;
    bc[2][2]=1;
    bc[2][3]=-1;
    bc[2][4]=-1;
    bc[3][1]=1;
    bc[3][2]=1;
    bc[3][3]=-1;
    bc[3][4]=-1;
    bc[4][1]=1;
    bc[4][3]=-1;
    bc[4][5]=-1;
    bc[5][1]=1;*/

    /*bc[0][0]=-1;
    bc[0][1]=1;
    bc[1][1]=-1;
    bc[1][2]=1;
    bc[2][1]=1;
    bc[2][2]=-1;
    bc[2][3]=-1;
    bc[2][2]=-1;
    bc[3][2]=1;
    bc[3][3]=-1;*/

    /*bc[0][0]=-1;
    bc[0][1]=1;
    bc[0][2]=1;
    bc[0][3]=1;
    bc[0][5]=-1;
    bc[1][0]=1;
    bc[1][1]=1;
    bc[1][2]=1;
    bc[1][3]=1;
    bc[1][4]=1;
    bc[2][0]=-1;
    bc[2][1]=1;
    bc[2][2]=1;
    bc[2][3]=-1;
    bc[2][4]=1;
    bc[2][5]=1;
    bc[3][1]=1;
    bc[3][2]=1;
    bc[3][3]=1;
    bc[3][4]=-1;
    bc[4][0]=1;
    bc[4][1]=1;
    bc[4][2]=1;
    bc[4][3]=-1;
    bc[4][4]=1;
    bc[5][1]=-1;
    bc[5][2]=-1;
    bc[5][3]=-1;
    bc[5][5]=1;*/

    bc[0][7]=1;
    bc[1][2]=-1;bc[1][7]=1;bc[1][8]=1;bc[1][9]=1;
    bc[2][3]=-1;bc[2][4]=1;bc[2][5]=1;bc[2][7]=1;bc[2][8]=1;
    bc[3][3]=1;bc[3][4]=-1;bc[3][5]=-1;bc[3][6]=1;bc[3][7]=1;bc[3][8]=-1;bc[3][9]=-1;
    bc[4][4]=1;bc[4][3]=1;bc[4][5]=-1;bc[4][6]=1;bc[4][7]=1;bc[4][8]=-1;bc[4][9]=-1;
    bc[5][4]=1;bc[5][3]=1;bc[5][5]=1;bc[5][6]=-1;bc[5][7]=1;bc[5][8]=1;bc[5][9]=-1;
    bc[6][3]=1;bc[6][4]=1;bc[6][5]=1;bc[6][6]=1;bc[6][7]=-1;bc[6][8]=-1;bc[6][9]=-1;
    bc[7][4]=-1;bc[7][5]=-1;bc[7][6]=-1;bc[7][7]=-1;bc[7][8]=-1;bc[7][9]=-1;
    bc[8][3]=-1;bc[8][4]=-1;bc[8][7]=1;bc[8][8]=1;
    bc[9][2]=-1;

    print_ban_co(bc);

    vector<toa_do> moves = generate_valid_moves(bc, player);
    cout<<endl<<"Nuoc di hop le cua nguoi choi "<<player<<": "<<endl;
    for (toa_do item : moves)
    {
        cout << "(" << item.x << ", " << item.y << ")" << endl;
    }
    cout<<endl;
    play_moves(bc, player, {0,8});
    print_ban_co(bc);
    /*play_moves(bc, player, {1,0});
    print_ban_co(bc);
    play_moves(bc, player, {1,5});
    print_ban_co(bc);*/

    return 0;
}
