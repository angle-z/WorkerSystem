//
//  SimpleWorker.hpp
//  WorkerSystem
//
//  Created by Angle on 2022/3/14.
//

#ifndef SimpleWorker_hpp
#define SimpleWorker_hpp

#include <stdio.h>

#endif /* SimpleWorker_hpp */
#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

class SimpleWorker:public Worker{
public:
    SimpleWorker(int id,string name,int dId);
    //显示员工信息
    virtual void showMessage();
    //获取员工部门名称
    virtual string getDIdName();
};

