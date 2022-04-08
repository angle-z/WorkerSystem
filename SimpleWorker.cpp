//
//  SimpleWorker.cpp
//  WorkerSystem
//
//  Created by Angle on 2022/3/14.
//

#include "SimpleWorker.hpp"
//构造函数
SimpleWorker::SimpleWorker(int id,string name,int dId){
    this->m_Id=id;
    this->m_name=name;
    this->m_dId=dId;
    
}
//显示员工信息
void SimpleWorker:: showMessage(){
    cout<<"员工编号："<<this->m_Id;
    cout<<"\t员工姓名："<<this->m_name;
    cout<<"\t员工职位："<<this->getDIdName();
    cout<<"\t岗位职责："<<"完成经理下发的任务"<<endl;
}
//获取员工部门名称
string SimpleWorker::getDIdName(){
    string DIdName="普通员工";
    return DIdName;
}
