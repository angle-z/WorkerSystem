//
//  Boss.cpp
//  WorkerSystem
//
//  Created by Angle on 2022/3/14.
//

#include "Boss.hpp"
//构造函数
Boss::Boss(int id,string name,int dId){
    this->m_Id=id;
    this->m_name=name;
    this->m_dId=dId;
    
}
//显示员工信息
void Boss:: showMessage(){
    cout<<"员工编号："<<this->m_Id;
    cout<<"\t员工姓名："<<this->m_name;
    cout<<"\t员工职位："<<this->getDIdName();
    cout<<"\t岗位职责："<<"管理整个公司"<<endl;
}
//获取员工部门名称
string Boss:: getDIdName(){
    string DIdName="大老板";
    return DIdName;
}
