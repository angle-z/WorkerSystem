//
//  WorkerManager.hpp
//  WorkerSystem
//
//  Created by Angle on 2022/3/14.
//

#ifndef WorkerManager_hpp
#define WorkerManager_hpp


#endif /* WorkerManager_hpp */
#include <stdio.h>
#include<iostream>
#include "Worker.h"
#include <fstream>
#define FILENAME "/Users/angle/Desktop/test.txt"




using namespace std;
#pragma once 
class WorkerManager{
public:
    WorkerManager();
    //菜单界面展示
    void ShowMenu();
    //0.退出管理系统
    void ExitSystem();
    //记录职工人数
    int m_EmpNum;
    //职工数组指针
    Worker** m_EmpArray;
    
    
    //1.增加职工信息
    void Add_Emp();
    
        //保存文件
        void Save();
        //文件是否为空
        bool m_FileIsEmpty;
        //得到文件中人数
        int get_EmpNum();
        //初始化文件中的人
        void init_File();
    
    //2.显示职工信息
    void DisplayMessage();
    //3.删除职工信息
    void DeleteMessage();
        //判断员工是否存在
        bool isExtend(int id,int &extend);
    //4.修改职工信息
    void ModifyMessage();
    //5.查找职工信息
    void FindMessage();
    //6.按照编号排序
    void SortMessage();
    //7.清空所有文档
    void CleanMessage();
    ~WorkerManager();
};
