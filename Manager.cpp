//
//  Manager.cpp
//  WorkerSystem
//
//  Created by Angle on 2022/3/14.
//

#include "Manager.hpp"
//构造函数
Manager::Manager(int id,string name,int dId){
    this->m_Id=id;
    this->m_name=name;
    this->m_dId=dId;
    
}
//显示员工信息
void Manager:: showMessage(){
    cout<<"员工编号："<<this->m_Id;
    cout<<"\t员工姓名："<<this->m_name;
    cout<<"\t员工职位："<<this->getDIdName();
    cout<<"\t\t岗位职责："<<"完成老板下发的任务"<<endl;
}
//获取员工部门名称
string Manager::getDIdName(){
    string DIdName="经理";
    return DIdName;
}
