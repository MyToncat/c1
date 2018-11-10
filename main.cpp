#include<stdlib.h>
#include <string.h>//strcpy,strcmp
#include <iostream>
#include <iomanip>//sewt
#include <fstream>//输入输出文件流

using namespace  std;
//结构体默认权限是public
//class默认权限是private；
class Student
{
protected:
    char name[20];
    char ID[20];//唯一标示
    char addr[100];
    char phone_num[12];//手机号码，非座机
    char sex[3];//
    int age;
    char email[20];
    Student *next_stu;//链接第一个成员

public:
    //数组类型返回指针，数组的没有置方法
    const char *getName() const {
        return name;
    }

    const char *getID() const {
        return ID;
    }

    const char *getAddr() const {
        return addr;
    }

    const char *getPhone_num() const {
        return phone_num;
    }

    const char *getSex() const {
        return sex;
    }

    int getAge() const {
        return age;
    }

    const char *getEmail() const {
        return email;
    }

    Student *getNext_stu() const {
        return next_stu;
    }
    //置
    void setAge(int age) {
        Student::age = age;
    }

    void setNext_stu(Student *next_stu) {
        Student::next_stu = next_stu;
    }
    void setName(char nam[20]){
        strcpy(Student::name,nam);
    }
    void setID(char temp_id[20]){
        strcpy(Student::ID,temp_id);
    }
    void setAddr(char temp_addr[100]){
        strcpy(Student::addr,temp_addr);
    }
    void setSex(char temp_sex[3]){
        strcpy(Student::sex,temp_sex);
    }
    void setPhone_num(char temp_phone_num[12]){
        strcpy(Student::phone_num,temp_phone_num);
    }
    void setEmail(char temp_email[20]){
        strcpy(Student::email,temp_email);
    }

    //构造方法
    //无参构造
    Student() {
        //先省略

    };
    //有参构造
    Student(char Sname[20],char SID[20],char Saddr[100],char Sphone_num[12],char Ssex[3], int Sage,char Semail[20],Student *next) {
        strcpy(name,Sname);
        strcpy(ID,SID);
        strcpy(addr,Saddr);
        strcpy(phone_num,Sphone_num);
        strcpy(sex,Ssex);
        age=Sage;
        strcpy(email,Semail);
        next_stu=next;
    };
    //显示输出个人信息
    void display(){
        cout<<setw(20)<<"姓名"<<setw(20)<<"ID"<<setw(12)<<"电话号码"<<setw(3)<<"年龄"<<setw(1)<<"性别"<<setw(17)<<"邮箱"<<setw(20)<<"地址"<<endl;
        cout<<setw(20)<<name<<setw(20)<<ID<<setw(12)<<phone_num<<setw(3)<<age<<setw(1)<<sex<<setw(17)<<email<<setw(20)<<addr<<endl;
    }

};

//通讯录管理系统
class Comminute_list{
private:
    int count;
    Student *fstu;
    Student *astu;
public:
    int getCount() const;

    Student *getFstu() const;

    Student *getAstu() const;

    void setCount(int count);

    void setFstu(Student *fstu);

    void setAstu(Student *astu);

    Comminute_list();//无参数初始化
    Comminute_list(char Sname[20],char SID[20],char Saddr[100],char Sphone_num[12],char Ssex[3], int Sage,char Semail[20] );//有参初始化
    ~Comminute_list();//析构，配合clear方法使用
    //
    void addMenber();//添加成员
    void updateMenber(char temp_id[20]);//更新成员
    void Insertmenber(char temp_id[20]);//插入成员
    void DeleMenber();//删除成员
    void SearchMenber(char stuid[20]);//查询
    void DisplayMenber();//显示全部，配合student.display
    void SaveToText();//保存成文本形式
    void Reload();//从文本形式读取
    void clear();//清空数据
};
//构造函数
Comminute_list::Comminute_list() {
    count=0;
    fstu=NULL;
    astu=NULL;
}
//构造函数；
Comminute_list::Comminute_list(char Sname[20],char SID[20],char Saddr[100],char Sphone_num[12],char Ssex[3], int Sage,char Semail[20]) {
    count=0;
    fstu=new Student(Sname,SID,Saddr,Sphone_num, Ssex, Sage,Semail,NULL);
    astu=fstu;
}

//析构函数
Comminute_list::~Comminute_list(){
    Student *next,*temp;
    next=this->getFstu();
    while (next!=NULL){
        temp=next;
        next=next->getNext_stu();
        delete temp;
    }
    this->setFstu(NULL);
}

//添加成员
void Comminute_list::addMenber() {
    char name[20];
    char ID[20];
    char addr[100];
    char phone_num[12];
    char sex[3];
    int age;
    char email[20];
    cout<<"请输入成员姓名："<<endl;
    cin>>name;
    cout<<"请输入学生ID："<<endl;
    cin>>ID;
    //这里是ID唯一，所以有判断错误的函数
    //省略该函数
    cout<<"请输入性别："<<endl;
    cin>>sex;
    cout<<"请输入年龄："<<endl;
    cin>>age;
    cout<<"请输入地址："<<endl;
    cin>>addr;
    cout<<"请输入邮箱："<<endl;
    cin>>email;
    cout<<"请输入电话号码："<<endl;
    cin>>phone_num;
    //临时保存
    Student *temp;
    temp=fstu;
    if(count==0||temp==NULL){
        cout<<"这是第一个通讯成员的录入！"<<endl;
        this->fstu=new Student(name,ID,addr,phone_num,sex,age,email,NULL);
        this->count++;
    }
    else if(count>=1||temp!=NULL){
        //把新节点保存到第一个
        fstu=new Student(name,ID,addr,phone_num,sex,age,email,NULL);
        //把其他节点附在新节点后面
        fstu->setNext_stu(temp);
        count++;
    }
}

//显示成员函数
void Comminute_list::DisplayMenber(){
    Student *fp=this->fstu;
    cout<<setw(6)<<"姓名"<<setw(10)<<"ID"<<setw(12)<<"电话号码"<<setw(6)<<"年龄"<<setw(6)<<"性别"<<setw(14)<<"邮箱"<<setw(20)<<"地址"<<endl;
    while (fp!=NULL){
        cout<<setw(6)<<fp->getName()<<setw(10)<<fp->getID()<<setw(12)<<fp->getPhone_num()<<setw(6)<<fp->getAge()<<setw(6)<<fp->getSex()<<setw(14)<<fp->getEmail()<<setw(20)<<fp->getAddr()<<endl;
        fp=fp->getNext_stu();
    }
}

//更新
void Comminute_list::updateMenber(char temp_id[20]){
    Student *fp=this->fstu;
    int choice;
    while (fp!=NULL){
        if((strcmp(temp_id,fp->getID()))==0){
            cout<<"找到要更新的成员信息,信息如下："<<endl;
            fp->display();//调用本身display函数输出信息
            zanding:
            cout<<"1：姓名 2：ID 3：电话号码 4:年龄 5：性别 6：邮箱 7：地址"<<endl;
            cout<<"请输入要更新的内容序号：";
            //省略对输入的数据合法性的判断
            cin>>choice;
            switch(choice){
                case 1:
                    cout<<"更改前的姓名："<<fp->getName()<<endl;
                    cout<<"请输入姓名：";
                    char temp_name[20];
                    cin>>temp_name;
                    fp->setName(temp_name);
                    cout<<"更改后的名字："<<fp->getName()<<endl;
                    break;
                case 2:
                    cout<<"更改前的ID："<<fp->getID()<<endl;
                    cout<<"请输入ID(不可重复)：";
                    //下面省略对ID合法性检测;
                    char temp_ID[20];
                    cin>>temp_ID;
                    cout<<"temp_ID:"<<temp_ID;
                    fp->setID(temp_ID);
                    cout<<"更改后的ID为："<<fp->getID()<<endl;
                    break;
                case 3:
                    cout<<"更改前的电话号码为："<< fp->getPhone_num()<<endl;
                    cout<<"请输入电话号码：";
                    char temp_phone_num[12];
                    cin>>temp_phone_num;
                    fp->setPhone_num(temp_phone_num);
                    cout<<"更改后的电话号码："<<fp->getPhone_num()<<endl;
                    break;
                case 4:
                    cout<<"更改前的年龄为："<<fp->getAge()<<endl;
                    cout<<"请输入年龄:";
                    int temp_age;
                    cin>>temp_age;
                    fp->setAge(temp_age);
                    cout<<"更改后的年龄："<<fp->getAge();
                    break;
                case 5:
                    cout<<"更改前的性别："<<fp->getSex()<<endl;
                    cout<<"请输入更改的性别：";
                    char temp_sex[3];
                    cin>>temp_sex;
                    fp->setSex(temp_sex);
                    cout<<"更改后的性别为："<<fp->getSex()<<endl;
                    break;
                case 6:
                    cout<<"更改前的邮箱为："<<fp->getEmail()<<endl;
                    cout<<"请输入更改的邮箱：";
                    char temp_email[20];
                    cin>>temp_email;
                    fp->setEmail(temp_email);
                    cout<<"更改后的邮箱："<<fp->getEmail()<<endl;
                    break;
                case 7:
                    cout<<"更改前的地址为："<<fp->getAddr()<<endl;
                    cout<<"请输入更新的地址：";
                    char temp_addr[100];
                    cin>>temp_addr;
                    fp->setAddr(temp_addr);
                    cout<<"更改后的地址："<<fp->getAddr();
                    break;
                default:
                    cout<<"输入序号错误！"<<endl;
                    break;
            }
            cout<<"更新成员信息操作完成！"<<endl;

            cout<<"是否需要需改本ID下的其他信息(y/n)";
            char temp_choice;
            cin>>temp_choice;
            if(temp_choice=='y'||temp_choice=='Y')
            {
                goto zanding;//测试使用
            }
            else
                break;
        }
        else{
            fp=fp->getNext_stu();
        }
    }
}
//插入
void Comminute_list::Insertmenber(char temp_id[20]){
    Student *fp=this->fstu;
    while (fp!=NULL)
    {
        if(strcmp(fp->getID(),temp_id)==0){
            cout<<"存在此ID号，是否继续执行插入（y/n）？";
        }
        char a;
        cin>>a;
        if(a=='y'||a=='Y')
        {
            //此处添加信息并插入
            this->addMenber();
            //刷新插入后的成员列表
            this->DisplayMenber();

        }
        else if(a=='n'||a=='N'){
            cout<<"取消插入！"<<endl;
        }
        break;//退出循环
        //省略判断；
    }
}

//删除
void Comminute_list::DeleMenber() {
    cout<<"请输入要删除的成员的ID：";
    char temp_id[20];
    Student *temp;//保存要删除的成员地址
    Student *temp1;//保存要删除成员信息的上一个成员地址
    Student *fp=this->getFstu();//第一个成员
    cin>>temp_id;
    bool flat= false;//标志位,标志是否存在此ID，默认为无
    //查找
    while (fp!=NULL){
        if((strcmp(fp->getID(),temp_id))==0)
        {
            cout<<"找到此ID:";
            cout<<fp->getID()<<endl;
            flat=true;//更改标志位
            cout<<"你是否确定要删除(y/n)？";
            char temp_flag;

            cin>>temp_flag;
            if(temp_flag=='Y'||temp_flag=='y'){
                temp=fp;
                temp1->setNext_stu(fp->getNext_stu());
                delete temp;
                cout<<"操作完成！"<<endl;
                count--;//人数减少；
                break;
            }
            else if(temp_flag=='N'||temp_flag=='n'){
                cout<<"取消删除！"<<endl;
                break;
            }
            else{
                cout<< "输入错误！"<<endl;
                break;
            }
        }
        else{
            temp1=fp;//保存要删除成员信息的上一个成员地址
            fp=fp->getNext_stu();
        }
    }
    if (!flat)
    {
        cout<<"删除失败！"<<endl;
    }

}
//查询
void Comminute_list::SearchMenber(char stuid[20]) {
    Student *next=this->getFstu();
    bool flag=false;//标志位，找到标志
    while (next!=NULL){
        if(strcmp(next->getID(),stuid)==0){
            cout<<"查找完成！"<<endl;
            cout<<"信息如下："<<endl;
            next->display();
            flag=true;
            break;
        }
        else {
            next=next->getNext_stu();
        }
    }
    if(flag){
        cout<<"扎到信息如下："<<endl;
        next->display();
    }
    else
    {

        cout<<"未找到此ID的成员信息,退出查询！"<<endl;

    }

}

//保存成文本
void Comminute_list::SaveToText() {
    ofstream outfile;
    outfile.open("Communicate_list.txt",ios::out);
    Student *next=this->getFstu();
    cout<<"正在保存。。。"<<endl;
    while (next!=NULL){
        outfile<<next->getName()<<"\t"<<next->getID()<<"\t"<<next->getAge()<<"\t"<<next->getSex()<<"\t"<<next->getEmail()<<"\t"<<next->getPhone_num()<<"\t"<<next->getAddr()<<"\n";
        next=next->getNext_stu();
    }
    outfile.close();
    cout<<"保存完成！"<<endl;


}
//从文本装载
void Comminute_list::Reload() {
    Student *next,*temp;
    bool flag= false;//标志位是否成功读取
    char temp_name[20];
    char temp_ID[20];
    char temp_addr[100];
    char temp_phone_num[12];
    char temp_sex[3];
    int temp_age;
    char temp_email[20];

    ifstream infile("Communicate_list.txt");
    while(infile>>temp_name>>temp_ID>>temp_age>>temp_sex>>temp_email>>temp_phone_num>>temp_addr){
        temp=fstu;//动态获取首指针，用于判断链表是否为空链表还是非空链表
        if (temp==NULL)
        {
            fstu=new Student(temp_name,temp_ID,temp_addr,temp_phone_num,temp_sex,temp_age,temp_email,NULL);
            count++;
        }
        else if(temp!=NULL)
        {
            fstu=new Student(temp_name,temp_ID,temp_addr,temp_phone_num,temp_sex,temp_age,temp_email,NULL);
            fstu->setNext_stu(temp);
            count++;
        }
        flag=true;
    }
    if(!flag){
        cout<<"无数据！"<<endl;
        infile.close();
    }
    else{
        cout<<"加载成功！"<<endl;
        infile.close();
        this->DisplayMenber();
    }


}

//清空
void Comminute_list::clear() {
    ifstream ffile("Communicate_list.txt",ios::trunc);//存在文件则删除，否创建性新文件
    Student *next=this->getFstu();
    Student *temp;
    while (next!=NULL){
        temp=next->getNext_stu();
        delete next;
        next=temp;
    }
    this->setFstu(NULL);
    ffile.close();
    cout<<"清空完成！！"<<endl;

}

//------------------置取--------------------
int Comminute_list::getCount() const {
    return count;
}

Student *Comminute_list::getFstu() const {
    return fstu;
}

Student *Comminute_list::getAstu() const {
    return astu;
}

void Comminute_list::setCount(int count) {
    Comminute_list::count = count;
}

void Comminute_list::setFstu(Student *fstu) {
    Comminute_list::fstu = fstu;
}

void Comminute_list::setAstu(Student *astu) {
    Comminute_list::astu = astu;
}

int main(){
    Comminute_list List;
    int choic;
    bool b1=false;//标志位，判断是否是第一次进入；
    int b2=0;//标志位，标志输入是否错误
    char ch;//临时保存y/n
    bool err=true;

    //主菜单界面设计
    system("color e");//更改控制台颜色
    menu:
    cout<<"------------------------------------"<<endl;
    cout<<"|     1:添加通讯录成员信息          |"<<endl;
    cout<<"|     2:显示通讯录成员信息          |"<<endl;
    cout<<"|     3:修改通讯录成员信息          |"<<endl;
    cout<<"|     4:查询通讯录成员成员信息      |"<<endl;
    cout<<"|     5:删除通讯录成员信息          |"<<endl;
    cout<<"|     6:保存通讯录信息为文本        |"<<endl;
    cout<<"|     7:装载通讯录成员信息          |"<<endl;
    cout<<"|     8:清除通讯录成员信息          |"<<endl;
    cout<<"|     9:退出通讯录管理系统          |"<<endl;
    cout<<"------------------------------------"<<endl;

    //有个问题：输入非数字，程序进入死循环，不知为何，上课问老师？

    cout<<"请输入一个操作的序列号：";
    while(b2==0){
        cin>>choic;
        //判断数据是否输入正确！错误则继续输入
        if (!(choic>=1&&choic<=9))
        {
            cout<<"输入的序号错误！退出程序"<<endl;
            break;

        }
        //以下是正确序号的信息
        if((choic==7)|(choic==1)){
            b1=true;
            break;
        }
        //若是9，退出程序
        if (choic==9)
        {
            cout<<"通讯录管理系统正在退出"<<endl;
            exit(0);

        }
        //对输入正确序列号，非9非1情况下处理
        if(!b1){
            cout<<"这是是第一次进入通讯录系统，请完成通讯录成员信息录入！！"<<endl;
            cout<<"是否需要录入成员信息(y/n)？";
            cin>>ch;
            if (ch=='y'||ch=='Y')
            {
                choic=1;
                b1=true;
                break;
            }
            else if(ch=='n'||ch=='N'){
                break;
            }
        }
        //正确且非第一次进入
        if(b1==true){
            break;
        }
    }
    cout<<endl;
    switch(choic)
    {
        case 1:
            List.addMenber();break;
        case 2:
            List.DisplayMenber();break;
        case 3:
            char temp[20];
            cout<<"请输入要更新成员信息的唯一ID：";
            cin>>temp;
            List.updateMenber(temp);
            break;
        case 4:
            char temp_id[20];
            cout<<"请输入要更新成员信息的唯一ID：";
            cin>>temp_id;
            List.SearchMenber(temp_id);
            break;
        case 5:
            List.DeleMenber();
            break;
        case 6:
            List.SaveToText();
            break;
        case 7:
            List.Reload();
            break;
        case 8:
            List.clear();
            break;

    }
    cout<<"是否要进行其他操作(y/n)?"<<endl;
    ch='n';
    cin>>ch;
    cout<<ch<<endl;
    cout<<endl;//换行
    if (ch=='Y'||ch=='y')
    {
        goto menu;
    }
    exit(1);
    return 0;
}