#include "Goods.h"
using namespace std;



void Good::setGoodAvailable(bool x){
    goodAvailable = x;
}

int Good::setAvailableGoods(int x){
    totalAvailableGoods += x;
    return 0;
}

int Good::getGoodAvailable() {
    return totalAvailableGoods;
}

int Good::setGoodsSent(int x){
    totalAvailableGoods -= x;
    totalGoodsSent += x;
    return totalAvailableGoods;
}
