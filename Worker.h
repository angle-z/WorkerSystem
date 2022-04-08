//
//  Worker.h
//  WorkerSystem
//
//  Created by Angle on 2022/3/14.
//

#ifndef Worker_h
#define Worker_h


#endif /* Worker_h */
#pragma once
#include<iostream>
using namespace std;
//定义一个所有员工的虚基类
class Worker{
public:
    //显示员工信息
    virtual void showMessage()=0;
    //获取员工部门名称
    virtual string getDIdName()=0;
    //员工编号
    int m_Id;
    //员工姓名
    string m_name;
    //员工部门编号
    int m_dId;
    //虚析构,解决父类指针释放子类对象不干净的问题
    virtual ~Worker(){
        
    }
};
