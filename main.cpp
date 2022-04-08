//
//  main.cpp
//  WorkerSystem
//
//  Created by Angle on 2022/3/14.
//

#include <iostream>
#include "WorkerManager.hpp"
#include "Worker.h"
#include "SimpleWorker.hpp"

void test(){
    Worker *worker=NULL;
    worker=new SimpleWorker(1,"张三",1);
    worker->showMessage();
    /*
    Person[] ps=new Person[10];
    ps[0]=new Person(name0,phone0,...)
    ps[1]=new Person(name1,phone1,...)
     */
    //Worker ** worker=new Worker*[];
}
int main(int argc, const char * argv[]) {
    WorkerManager wm;
    
    while(true){
    //显示菜单
    wm.ShowMenu();
    //测试
    // test();
    //定义选择按钮
    int choice;
    cin>>choice;
    switch (choice) {
        case 0:
            wm.ExitSystem();
            break;
        case 1:
            wm.Add_Emp();
            break;
        case 2:
            wm.DisplayMessage();
            break;
        case 3:
            wm.DeleteMessage();
            break;
        case 4:
            wm.ModifyMessage();
            break;
        case 5:
            wm.FindMessage();
            break;
        case 6:
            wm.SortMessage();
            break;
        case 7:
            wm.CleanMessage();
            break;
        default:
            break;
    }
        wm.Save();
    }
}
