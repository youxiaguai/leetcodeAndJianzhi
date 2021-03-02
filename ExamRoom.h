#pragma once
#include "common.h"
struct  Set
{
    int val;
    Set* next = nullptr;
};
class ExamRoom
{
public:
    Set* start = new Set();
    Set* end = new Set();
    int N;
    int next = 0;
    ExamRoom(int N) {
        this->N = N;
        start->val = -1;
    }

    int seat() {
        if (start->val == -1) {
            start->val = 0;
            //cout<<"pos "<<0<<"start"<<endl;
            return 0;
        }

        int distance;
        Set* tmp = new Set();

        Set* pre = start->val == 0 ? start : start->next;
        Set* cur = nullptr;

        if (pre) cur = pre->next;
        if (cur == nullptr && start->val == 0) {
            tmp->val = N - 1;
            start->next = tmp;
            end = tmp;
            //cout<<"pos "<<N-1<<"distance "<<N-1<<endl;
            return N - 1;
        }



       
    };
};
