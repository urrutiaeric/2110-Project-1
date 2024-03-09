#ifndef GOODS_H
#define GOODS_H
#include <iostream>
#include <vector>

using namespace std;

class Good {
    private:
    bool goodAvailable = false;
    int totalAvailableGoods = 0;
    int totalGoodsSent = 0;

    public:
        
        void setGoodAvailable( bool x);
        int setAvailableGoods(int x);
        int getGoodAvailable();
        int setGoodsSent(int x);

        

};

#endif
