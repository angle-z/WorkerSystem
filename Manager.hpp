//
//  Manager.hpp
//  WorkerSystem
//
//  Created by Angle on 2022/3/14.
//

#ifndef Manager_hpp
#define Manager_hpp

#include <stdio.h>

#endif /* Manager_hpp */
#include<iostream>
#include"Worker.h"
using namespace std;
#pragma once
class Manager:public Worker{
public:
    Manager(int id,string name,int dId);
    //显示员工信息
    virtual void showMessage();
    //获取员工部门名称
    virtual string getDIdName();
};

