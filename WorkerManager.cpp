//
//  WorkerManager.cpp
//  WorkerSystem
//
//  Created by Angle on 2022/3/14.
//

#include "WorkerManager.hpp"
#include "Worker.h"
#include "SimpleWorker.hpp"
#include "Manager.hpp"
#include "Boss.hpp"

WorkerManager::WorkerManager(){
    //文件不存在
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open()){
        cout<<"文件不存在"<<endl;
        this->m_EmpNum=0;
        this->m_FileIsEmpty=true;
        this->m_EmpArray=NULL;
        ifs.close();
        return;
        
    }
    //文件存在且数据为空
    char ch;
    ifs>>ch;
    if(ifs.eof()){
       // cout<<"文件不存在"<<endl;
        this->m_EmpNum=0;
        this->m_FileIsEmpty=true;
        this->m_EmpArray=NULL;
        ifs.close();
        return;
    }
    //文件存在并且数据不为空
    int num=this->get_EmpNum();
   // cout<<"职工个数是"<<num<<"个"<<endl;
    this->m_EmpNum=num;
    
    //初始化职工
    this->m_EmpArray=new Worker *[this->m_EmpNum];
    init_File();
//    for(int i=0;i<m_EmpNum;i++){
//        cout<<this->m_EmpArray[i]->m_Id<<" ";
//        cout<<this->m_EmpArray[i]->m_name<<" ";
//        cout<<this->m_EmpArray[i]->getDIdName()<<endl;
//    }
    
}
//得到文件中人数
int WorkerManager:: get_EmpNum(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int num=0;
    string buf;
    while(getline(ifs,buf)){
        cout<<buf<<endl;
        num++;
    }
    ifs.close();
    return num;
}
//初始化文件中的人
void WorkerManager:: init_File(){
    
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    int id;
    string name;
    string department;
    int index=0;
    while(ifs>>id&&ifs>>name&&ifs>>department){
        
       Worker * worker=NULL;
        if(department=="普通员工"){
            worker=new SimpleWorker(id,name,1);
        }else if(department=="经理"){
            worker=new Manager(id,name,2);
        }else if(department=="大老板"){
            worker=new Boss(id,name,3);
        }else{
            worker=new SimpleWorker(id,name,1);
        }
        this->m_EmpArray[index]=worker;
        index++;
        
        
    }
  //  cout<<"初始化成功！"<<endl;
}
//展示菜单
void WorkerManager::ShowMenu(){
    cout<<"--------------------------"<<endl;
    cout<<"-----欢迎来到职工管理系统-----"<<endl;
    cout<<"-------0 退出管理系统-------"<<endl;
    cout<<"-------1 增加职工信息-------"<<endl;
    cout<<"-------2 显示职工信息-------"<<endl;
    cout<<"-------3 删除离职职工-------"<<endl;
    cout<<"-------4 修改职工信息-------"<<endl;
    cout<<"-------5 查找职工信息-------"<<endl;
    cout<<"-------6 按照编号排序-------"<<endl;
    cout<<"-------7 清空所有文档-------"<<endl;
    cout<<"--------------------------"<<endl;
}
//0.退出管理系统
void WorkerManager::ExitSystem(){
    cout<<"欢迎下次使用"<<endl;
    exit(0);
}
//1.增加职工信息
void WorkerManager:: Add_Emp(){
    
    cout<<"请输入添加职工的数量"<<endl;
    int AddNum=0;//记录新添加职工数量
    cin>>AddNum;
    if(AddNum){
        int newSize=this->m_EmpNum+AddNum;//需要开辟的空间大小（旧空间+新空间）
        //开辟新空间
        Worker** newSpace=new Worker*[newSize];
        //将原来数据放入新空间
        if(this->m_EmpArray!=NULL){
            for(int i=0;i<this->m_EmpNum;i++){
                newSpace[i]=this->m_EmpArray[i];
            }
        }
        //将新数据添加到新空间
        for(int i=0;i<AddNum;i++){
            int id;//职工编号
            string name;//姓名
            int dId;//部门选择
            cout<<"请输入新员工编号："<<endl;
            cin>>id;
            cout<<"请输入员工姓名："<<endl;
            cin>>name;
            cout<<"请选择职工部门：1、普通员工 2、经理 3、老板"<<endl;
            cin>>dId;
            
            Worker * worker=NULL;
            switch (dId) {
                case 1:
                    worker=new SimpleWorker(id,name,dId);
                    break;
                case 2:
                    worker=new Manager(id,name,dId);
                    break;
                case 3:
                    worker=new Boss(id,name,dId);
                    break;
                default:
                    break;
            }
            //将创建的指针保存到数组中
            newSpace[this->m_EmpNum+i]=worker;
        }
        //释放原有空间
        delete [] this->m_EmpArray;
        //更新数组指向
        this->m_EmpArray=newSpace;
        //更新新的职工人数
        this->m_EmpNum=newSize;
        //将为空标志设置为false；
        this->m_FileIsEmpty=false;
        //提示添加成功
        cout<<"成功添加"<<AddNum<<"名职工！"<<endl; 
        
    }else{
        cout<<"输入有误！"<<endl;
    }
}
//保存文件
void WorkerManager::Save(){
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    if(!ofs.is_open()){
        cout<<"文件无法打开"<<endl;
    }
    for(int i=0;i<this->m_EmpNum;i++){
        ofs<<this->m_EmpArray[i]->m_Id<<" "
        <<this->m_EmpArray[i]->m_name<<" "
        <<this->m_EmpArray[i]->getDIdName()<<endl;
    }
    ofs.close();
}
//2.显示职工信息
void WorkerManager:: DisplayMessage(){
    if(this->m_FileIsEmpty){
        cout<<"职工信息为空！"<<endl;
    }else{
        for(int i=0;i<this->m_EmpNum;i++){
            this->m_EmpArray[i]->showMessage();
        }
    }
}
//判断员工是否存在
bool WorkerManager::isExtend(int id,int &extend){
    for(int i=0;i<this->m_EmpNum;i++){
        if(id==this->m_EmpArray[i]->m_Id){
            extend=i;
            return true;
        }
    }
    return false;
}
//3.删除职工信息
void WorkerManager:: DeleteMessage(){
    cout<<"请输入要删除的职工编号："<<endl;
    int id;
    cin>>id;
    int array_i;
    //判断职工是否存在
    if(isExtend(id,array_i)){
//        cout<<"该员工存在！"<<endl;
//        cout<<array_i;
        for(int i=array_i;i<(this->m_EmpNum-1);i++){
            this->m_EmpArray[i]=this->m_EmpArray[i+1];
        }
        m_EmpNum--;
        cout<<"删除成功！"<<endl;
        
    }else{
        cout<<"该员工不存在！"<<endl;
    }
}
//4.修改职工信息
void WorkerManager:: ModifyMessage(){
    cout<<"请输入想要修改的职工编号："<<endl;
    int id;
    cin>>id;
    int array_i;
    if(isExtend(id, array_i)){
        int a_id;
        string a_name;
        int a_dId;
        cout<<"请输入修改的编号：";
        cin>>a_id;
        cout<<"请输入修改的姓名：";
        cin>>a_name;
        cout<<"请输入修改的职位编号1、普通员工 2、经理 3、大老板:";
        cin>>a_dId;
        Worker* work=NULL;
        switch (a_dId) {
            case 1:
                work=new SimpleWorker(a_id,a_name,a_dId);
                break;
            case 2:
                work=new Manager(a_id,a_name,a_dId);
                break;
            case 3:
                work=new Boss(a_id,a_name,a_dId);
                break;
            default:
                break;
        }
        this->m_EmpArray[array_i]=work;
        
    }else{
        cout<<"该员工不存在！"<<endl;
    }
}
//5.查找职工信息
void WorkerManager:: FindMessage(){
    cout<<"请输入想要查找的职工编号："<<endl;
    int id;
    cin>>id;
    int array_i;
    if(isExtend(id, array_i)){
        this->m_EmpArray[array_i]->showMessage();
    }else{
        cout<<"该员工不存在！"<<endl;
    }
}
//6.按照编号排序

void WorkerManager:: SortMessage(){
    cout<<"请选择排序方式：1、按编号顺序排序 2、按编号逆序排序"<<endl;
    int choice;
    cin>>choice;
    for(int i=0;i<m_EmpNum;i++){
        int minOrMax=i;
        for(int j=i+1;j<m_EmpNum;j++){
            
            if(choice==1){
                if(m_EmpArray[minOrMax]->m_Id>m_EmpArray[j]->m_Id){
                    minOrMax=j;
                }
                
            }else if(choice==2){
                if(m_EmpArray[minOrMax]->m_Id<m_EmpArray[j]->m_Id){
                    minOrMax=j;
                }
                
            }else{
                cout<<"请输入范围内选项"<<endl;
                return;
            }
        }
        if(i!=minOrMax){
            Worker *temp=m_EmpArray[i];
            m_EmpArray[i]=m_EmpArray[minOrMax];
            m_EmpArray[minOrMax]=temp;
        }
    }
    cout<<"排序成功！排序结果为："<<endl;
    this->Save();
    this->DisplayMessage();
}
//7.清空所有文档
void WorkerManager:: CleanMessage(){
    cout<<"是否确认清空？"<<endl;
    cout<<"1.确认   2.返回"<<endl;
    int select=0;
    cin>>select;
    if(select==1){
        //文件存在则删除并重新创建
        ofstream ofs;
        ofs.open(FILENAME,ios::trunc);
        ofs.close();
        //堆区的对象数据和数组都释放干净
        if(this->m_EmpArray!=NULL){
            for(int i=0;i<m_EmpNum;i++){
                if(this->m_EmpArray[i]!=NULL){
                    
                    delete this->m_EmpArray[i];
                    this->m_EmpArray[i]=NULL;
                }
            }
            delete[] this->m_EmpArray;
            this->m_EmpArray=NULL;
            this->m_EmpNum=0;
            this->m_FileIsEmpty=true;
        }
        cout<<"清空成功！"<<endl;
    }
    else{
        
    }
}
//析构函数
WorkerManager::~WorkerManager(){
    if(this->m_EmpArray!=NULL){
        for(int i=0;i<m_EmpNum;i++){
            if(this->m_EmpArray[i]!=NULL){
                
                delete this->m_EmpArray[i];
                this->m_EmpArray[i]=NULL;
            }
        }
        delete [] this->m_EmpArray;
        this->m_EmpArray=NULL;
    }
}
