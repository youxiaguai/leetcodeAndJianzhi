#include <iostream>
//#include "math.h"
#include <cmath>

using namespace std;

int xuanzhuan()
{
    int x1, y1, z1;
    int n, m;
    int Q;
    cin >> x1 >> y1 >> z1;
    cin >> n >> m;
    cin >> Q;
    int tempX = m / 2;
    int tempY = n / 2;

    // 查询若干次
    for (int i = 0; i < Q; i++)
    {
        int x0 = 0, y0 = 0;
        cin >> x0 >> y0;
        
        // 判断旋转时针方向
        // 逆时针
        if (z1 > x1)
        {
            // 次数
            int temp = z1 - x1;

            // 旋转后的坐标
            for (int j = 0; j < temp; j++)
            {
                x0 = (x0 - tempX) * cos(1 / 2) - (y0 - tempY) * sin(1 / 2) + tempX;
                y0 = (x0 - tempX) * sin(1 / 2) + (y0 - tempY) * cos(1 / 2) + tempY;

            }

            // 反转
            if (y1 % 2 == 0)
            {
                cout << x0 << " " << y0 << endl;
            }
            else if (y1 % 2 == 1)
            {
                x0 = (x0 - m) > 0 ? x0 - m : m - x0;
                cout << x0 << " " << y0 << endl;
            }
        }
        // 顺时针
        else if (z1 < x1)
        {
            int temp = x1 - z1;

            // 旋转后的坐标
            for (int j = 0; j < temp; j++)
            {
                x0 = (x0 - tempX) * cos(1 / 2) - (y0 - tempY) * sin(1 / 2) + tempX;
                y0 = -(x0 - tempX) * sin(1 / 2) + (y0 - tempY) * cos(1 / 2) + tempY;

            }

            // 反转
            if (y1 % 2 == 0)
            {
                cout << x0 << " " << y0 << endl;
            }
            else if (y1 % 2 == 1)
            {
                x0 = (x0 - m) > 0 ? x0 - m : m - x0;
                cout << x0 << " " << y0 << endl;
            }
        }
        // 不旋转
        else {
            // 反转
            if (y1 % 2 == 0)
            {
                cout << x0 << " " << y0 << endl;
            }
            else if (y1 % 2 == 1)
            {
                x0 = (x0 - m) > 0 ? x0 - m : m - x0;
                cout << x0 << " " << y0 << endl;
            }
        }
    }
    return 0;

}


