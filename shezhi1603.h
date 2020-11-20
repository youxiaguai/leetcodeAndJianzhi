#pragma once
class ParkingSystem {
private:
    int big;
    int medium;
    int small;
public:
    ParkingSystem(int big1, int medium, int small) {
        this->big = big1;
        this->medium = medium;
        this->small = small;
            
            
            
    }
    void setBig(int big)
    {
        this->big = big;
    }
    int getBig()
    {
        return big;
    }
    void setMedium(int medium)
    {
        this->medium = medium;
    }
    int getMedium()
    {
        return medium;
    }
    void setSmall(int small)
    {
        this->small = small;
    }
    int getSmall()
    {
        return small;
    }
    
    bool addCar(int carType) {
        if (carType == 1)
        {
            int bigNUm = getBig();
            if (bigNUm > 0)
            {
                bigNUm -= 1;
                setBig(bigNUm);
                return true;
            }
            
        }else  if (carType == 2)
        {
            int MediumNUm = getMedium();
            if (MediumNUm > 0)
            {
                MediumNUm -= 1;
                setMedium(MediumNUm);
                return true;
            }
           
        }else  if (carType == 3)
        {
            int smallNUm = getSmall();
            if (smallNUm > 0)
            {
                smallNUm-=1;
                setSmall(smallNUm);
                return true;
            }
            
        }
        return false;

    }


};