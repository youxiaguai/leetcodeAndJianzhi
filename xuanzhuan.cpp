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

    // ��ѯ���ɴ�
    for (int i = 0; i < Q; i++)
    {
        int x0 = 0, y0 = 0;
        cin >> x0 >> y0;
        
        // �ж���תʱ�뷽��
        // ��ʱ��
        if (z1 > x1)
        {
            // ����
            int temp = z1 - x1;

            // ��ת�������
            for (int j = 0; j < temp; j++)
            {
                x0 = (x0 - tempX) * cos(1 / 2) - (y0 - tempY) * sin(1 / 2) + tempX;
                y0 = (x0 - tempX) * sin(1 / 2) + (y0 - tempY) * cos(1 / 2) + tempY;

            }

            // ��ת
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
        // ˳ʱ��
        else if (z1 < x1)
        {
            int temp = x1 - z1;

            // ��ת�������
            for (int j = 0; j < temp; j++)
            {
                x0 = (x0 - tempX) * cos(1 / 2) - (y0 - tempY) * sin(1 / 2) + tempX;
                y0 = -(x0 - tempX) * sin(1 / 2) + (y0 - tempY) * cos(1 / 2) + tempY;

            }

            // ��ת
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
        // ����ת
        else {
            // ��ת
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


