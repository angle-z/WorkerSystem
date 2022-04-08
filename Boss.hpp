//
//  Boss.hpp
//  WorkerSystem
//
//  Created by Angle on 2022/3/14.
//

#ifndef Boss_hpp
#define Boss_hpp

#include <stdio.h>

#endif /* Boss_hpp */
#include<iostream>
#include"Worker.h"
using namespace std;
#pragma once
class Boss:public Worker{
public:
    Boss(int id,string name,int dId);
    //显示员工信息
    virtual void showMessage();
    //获取员工部门名称
    virtual string getDIdName();
};
