#include<stdlib.h>
#include <string.h>//strcpy,strcmp
#include <iostream>
#include <iomanip>//sewt
#include <fstream>//��������ļ���

using namespace  std;
//�ṹ��Ĭ��Ȩ����public
//classĬ��Ȩ����private��
class Student
{
protected:
    char name[20];
    char ID[20];//Ψһ��ʾ
    char addr[100];
    char phone_num[12];//�ֻ����룬������
    char sex[3];//
    int age;
    char email[20];
    Student *next_stu;//���ӵ�һ����Ա

public:
    //�������ͷ���ָ�룬�����û���÷���
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
    //��
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

    //���췽��
    //�޲ι���
    Student() {
        //��ʡ��

    };
    //�вι���
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
    //��ʾ���������Ϣ
    void display(){
        cout<<setw(20)<<"����"<<setw(20)<<"ID"<<setw(12)<<"�绰����"<<setw(3)<<"����"<<setw(1)<<"�Ա�"<<setw(17)<<"����"<<setw(20)<<"��ַ"<<endl;
        cout<<setw(20)<<name<<setw(20)<<ID<<setw(12)<<phone_num<<setw(3)<<age<<setw(1)<<sex<<setw(17)<<email<<setw(20)<<addr<<endl;
    }

};

//ͨѶ¼����ϵͳ
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

    Comminute_list();//�޲�����ʼ��
    Comminute_list(char Sname[20],char SID[20],char Saddr[100],char Sphone_num[12],char Ssex[3], int Sage,char Semail[20] );//�вγ�ʼ��
    ~Comminute_list();//���������clear����ʹ��
    //
    void addMenber();//��ӳ�Ա
    void updateMenber(char temp_id[20]);//���³�Ա
    void Insertmenber(char temp_id[20]);//�����Ա
    void DeleMenber();//ɾ����Ա
    void SearchMenber(char stuid[20]);//��ѯ
    void DisplayMenber();//��ʾȫ�������student.display
    void SaveToText();//������ı���ʽ
    void Reload();//���ı���ʽ��ȡ
    void clear();//�������
};
//���캯��
Comminute_list::Comminute_list() {
    count=0;
    fstu=NULL;
    astu=NULL;
}
//���캯����
Comminute_list::Comminute_list(char Sname[20],char SID[20],char Saddr[100],char Sphone_num[12],char Ssex[3], int Sage,char Semail[20]) {
    count=0;
    fstu=new Student(Sname,SID,Saddr,Sphone_num, Ssex, Sage,Semail,NULL);
    astu=fstu;
}

//��������
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

//��ӳ�Ա
void Comminute_list::addMenber() {
    char name[20];
    char ID[20];
    char addr[100];
    char phone_num[12];
    char sex[3];
    int age;
    char email[20];
    cout<<"�������Ա������"<<endl;
    cin>>name;
    cout<<"������ѧ��ID��"<<endl;
    cin>>ID;
    //������IDΨһ���������жϴ���ĺ���
    //ʡ�Ըú���
    cout<<"�������Ա�"<<endl;
    cin>>sex;
    cout<<"���������䣺"<<endl;
    cin>>age;
    cout<<"�������ַ��"<<endl;
    cin>>addr;
    cout<<"���������䣺"<<endl;
    cin>>email;
    cout<<"������绰���룺"<<endl;
    cin>>phone_num;
    //��ʱ����
    Student *temp;
    temp=fstu;
    if(count==0||temp==NULL){
        cout<<"���ǵ�һ��ͨѶ��Ա��¼�룡"<<endl;
        this->fstu=new Student(name,ID,addr,phone_num,sex,age,email,NULL);
        this->count++;
    }
    else if(count>=1||temp!=NULL){
        //���½ڵ㱣�浽��һ��
        fstu=new Student(name,ID,addr,phone_num,sex,age,email,NULL);
        //�������ڵ㸽���½ڵ����
        fstu->setNext_stu(temp);
        count++;
    }
}

//��ʾ��Ա����
void Comminute_list::DisplayMenber(){
    Student *fp=this->fstu;
    cout<<setw(6)<<"����"<<setw(10)<<"ID"<<setw(12)<<"�绰����"<<setw(6)<<"����"<<setw(6)<<"�Ա�"<<setw(14)<<"����"<<setw(20)<<"��ַ"<<endl;
    while (fp!=NULL){
        cout<<setw(6)<<fp->getName()<<setw(10)<<fp->getID()<<setw(12)<<fp->getPhone_num()<<setw(6)<<fp->getAge()<<setw(6)<<fp->getSex()<<setw(14)<<fp->getEmail()<<setw(20)<<fp->getAddr()<<endl;
        fp=fp->getNext_stu();
    }
}

//����
void Comminute_list::updateMenber(char temp_id[20]){
    Student *fp=this->fstu;
    int choice;
    while (fp!=NULL){
        if((strcmp(temp_id,fp->getID()))==0){
            cout<<"�ҵ�Ҫ���µĳ�Ա��Ϣ,��Ϣ���£�"<<endl;
            fp->display();//���ñ���display���������Ϣ
            zanding:
            cout<<"1������ 2��ID 3���绰���� 4:���� 5���Ա� 6������ 7����ַ"<<endl;
            cout<<"������Ҫ���µ�������ţ�";
            //ʡ�Զ���������ݺϷ��Ե��ж�
            cin>>choice;
            switch(choice){
                case 1:
                    cout<<"����ǰ��������"<<fp->getName()<<endl;
                    cout<<"������������";
                    char temp_name[20];
                    cin>>temp_name;
                    fp->setName(temp_name);
                    cout<<"���ĺ�����֣�"<<fp->getName()<<endl;
                    break;
                case 2:
                    cout<<"����ǰ��ID��"<<fp->getID()<<endl;
                    cout<<"������ID(�����ظ�)��";
                    //����ʡ�Զ�ID�Ϸ��Լ��;
                    char temp_ID[20];
                    cin>>temp_ID;
                    cout<<"temp_ID:"<<temp_ID;
                    fp->setID(temp_ID);
                    cout<<"���ĺ��IDΪ��"<<fp->getID()<<endl;
                    break;
                case 3:
                    cout<<"����ǰ�ĵ绰����Ϊ��"<< fp->getPhone_num()<<endl;
                    cout<<"������绰���룺";
                    char temp_phone_num[12];
                    cin>>temp_phone_num;
                    fp->setPhone_num(temp_phone_num);
                    cout<<"���ĺ�ĵ绰���룺"<<fp->getPhone_num()<<endl;
                    break;
                case 4:
                    cout<<"����ǰ������Ϊ��"<<fp->getAge()<<endl;
                    cout<<"����������:";
                    int temp_age;
                    cin>>temp_age;
                    fp->setAge(temp_age);
                    cout<<"���ĺ�����䣺"<<fp->getAge();
                    break;
                case 5:
                    cout<<"����ǰ���Ա�"<<fp->getSex()<<endl;
                    cout<<"��������ĵ��Ա�";
                    char temp_sex[3];
                    cin>>temp_sex;
                    fp->setSex(temp_sex);
                    cout<<"���ĺ���Ա�Ϊ��"<<fp->getSex()<<endl;
                    break;
                case 6:
                    cout<<"����ǰ������Ϊ��"<<fp->getEmail()<<endl;
                    cout<<"��������ĵ����䣺";
                    char temp_email[20];
                    cin>>temp_email;
                    fp->setEmail(temp_email);
                    cout<<"���ĺ�����䣺"<<fp->getEmail()<<endl;
                    break;
                case 7:
                    cout<<"����ǰ�ĵ�ַΪ��"<<fp->getAddr()<<endl;
                    cout<<"��������µĵ�ַ��";
                    char temp_addr[100];
                    cin>>temp_addr;
                    fp->setAddr(temp_addr);
                    cout<<"���ĺ�ĵ�ַ��"<<fp->getAddr();
                    break;
                default:
                    cout<<"������Ŵ���"<<endl;
                    break;
            }
            cout<<"���³�Ա��Ϣ������ɣ�"<<endl;

            cout<<"�Ƿ���Ҫ��ı�ID�µ�������Ϣ(y/n)";
            char temp_choice;
            cin>>temp_choice;
            if(temp_choice=='y'||temp_choice=='Y')
            {
                goto zanding;//����ʹ��
            }
            else
                break;
        }
        else{
            fp=fp->getNext_stu();
        }
    }
}
//����
void Comminute_list::Insertmenber(char temp_id[20]){
    Student *fp=this->fstu;
    while (fp!=NULL)
    {
        if(strcmp(fp->getID(),temp_id)==0){
            cout<<"���ڴ�ID�ţ��Ƿ����ִ�в��루y/n����";
        }
        char a;
        cin>>a;
        if(a=='y'||a=='Y')
        {
            //�˴������Ϣ������
            this->addMenber();
            //ˢ�²����ĳ�Ա�б�
            this->DisplayMenber();

        }
        else if(a=='n'||a=='N'){
            cout<<"ȡ�����룡"<<endl;
        }
        break;//�˳�ѭ��
        //ʡ���жϣ�
    }
}

//ɾ��
void Comminute_list::DeleMenber() {
    cout<<"������Ҫɾ���ĳ�Ա��ID��";
    char temp_id[20];
    Student *temp;//����Ҫɾ���ĳ�Ա��ַ
    Student *temp1;//����Ҫɾ����Ա��Ϣ����һ����Ա��ַ
    Student *fp=this->getFstu();//��һ����Ա
    cin>>temp_id;
    bool flat= false;//��־λ,��־�Ƿ���ڴ�ID��Ĭ��Ϊ��
    //����
    while (fp!=NULL){
        if((strcmp(fp->getID(),temp_id))==0)
        {
            cout<<"�ҵ���ID:";
            cout<<fp->getID()<<endl;
            flat=true;//���ı�־λ
            cout<<"���Ƿ�ȷ��Ҫɾ��(y/n)��";
            char temp_flag;

            cin>>temp_flag;
            if(temp_flag=='Y'||temp_flag=='y'){
                temp=fp;
                temp1->setNext_stu(fp->getNext_stu());
                delete temp;
                cout<<"������ɣ�"<<endl;
                count--;//�������٣�
                break;
            }
            else if(temp_flag=='N'||temp_flag=='n'){
                cout<<"ȡ��ɾ����"<<endl;
                break;
            }
            else{
                cout<< "�������"<<endl;
                break;
            }
        }
        else{
            temp1=fp;//����Ҫɾ����Ա��Ϣ����һ����Ա��ַ
            fp=fp->getNext_stu();
        }
    }
    if (!flat)
    {
        cout<<"ɾ��ʧ�ܣ�"<<endl;
    }

}
//��ѯ
void Comminute_list::SearchMenber(char stuid[20]) {
    Student *next=this->getFstu();
    bool flag=false;//��־λ���ҵ���־
    while (next!=NULL){
        if(strcmp(next->getID(),stuid)==0){
            cout<<"������ɣ�"<<endl;
            cout<<"��Ϣ���£�"<<endl;
            next->display();
            flag=true;
            break;
        }
        else {
            next=next->getNext_stu();
        }
    }
    if(flag){
        cout<<"������Ϣ���£�"<<endl;
        next->display();
    }
    else
    {

        cout<<"δ�ҵ���ID�ĳ�Ա��Ϣ,�˳���ѯ��"<<endl;

    }

}

//������ı�
void Comminute_list::SaveToText() {
    ofstream outfile;
    outfile.open("Communicate_list.txt",ios::out);
    Student *next=this->getFstu();
    cout<<"���ڱ��档����"<<endl;
    while (next!=NULL){
        outfile<<next->getName()<<"\t"<<next->getID()<<"\t"<<next->getAge()<<"\t"<<next->getSex()<<"\t"<<next->getEmail()<<"\t"<<next->getPhone_num()<<"\t"<<next->getAddr()<<"\n";
        next=next->getNext_stu();
    }
    outfile.close();
    cout<<"������ɣ�"<<endl;


}
//���ı�װ��
void Comminute_list::Reload() {
    Student *next,*temp;
    bool flag= false;//��־λ�Ƿ�ɹ���ȡ
    char temp_name[20];
    char temp_ID[20];
    char temp_addr[100];
    char temp_phone_num[12];
    char temp_sex[3];
    int temp_age;
    char temp_email[20];

    ifstream infile("Communicate_list.txt");
    while(infile>>temp_name>>temp_ID>>temp_age>>temp_sex>>temp_email>>temp_phone_num>>temp_addr){
        temp=fstu;//��̬��ȡ��ָ�룬�����ж������Ƿ�Ϊ�������Ƿǿ�����
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
        cout<<"�����ݣ�"<<endl;
        infile.close();
    }
    else{
        cout<<"���سɹ���"<<endl;
        infile.close();
        this->DisplayMenber();
    }


}

//���
void Comminute_list::clear() {
    ifstream ffile("Communicate_list.txt",ios::trunc);//�����ļ���ɾ�����񴴽������ļ�
    Student *next=this->getFstu();
    Student *temp;
    while (next!=NULL){
        temp=next->getNext_stu();
        delete next;
        next=temp;
    }
    this->setFstu(NULL);
    ffile.close();
    cout<<"�����ɣ���"<<endl;

}

//------------------��ȡ--------------------
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
    bool b1=false;//��־λ���ж��Ƿ��ǵ�һ�ν��룻
    int b2=0;//��־λ����־�����Ƿ����
    char ch;//��ʱ����y/n
    bool err=true;

    //���˵��������
    system("color e");//���Ŀ���̨��ɫ
    menu:
    cout<<"------------------------------------"<<endl;
    cout<<"|     1:���ͨѶ¼��Ա��Ϣ          |"<<endl;
    cout<<"|     2:��ʾͨѶ¼��Ա��Ϣ          |"<<endl;
    cout<<"|     3:�޸�ͨѶ¼��Ա��Ϣ          |"<<endl;
    cout<<"|     4:��ѯͨѶ¼��Ա��Ա��Ϣ      |"<<endl;
    cout<<"|     5:ɾ��ͨѶ¼��Ա��Ϣ          |"<<endl;
    cout<<"|     6:����ͨѶ¼��ϢΪ�ı�        |"<<endl;
    cout<<"|     7:װ��ͨѶ¼��Ա��Ϣ          |"<<endl;
    cout<<"|     8:���ͨѶ¼��Ա��Ϣ          |"<<endl;
    cout<<"|     9:�˳�ͨѶ¼����ϵͳ          |"<<endl;
    cout<<"------------------------------------"<<endl;

    //�и����⣺��������֣����������ѭ������֪Ϊ�Σ��Ͽ�����ʦ��

    cout<<"������һ�����������кţ�";
    while(b2==0){
        cin>>choic;
        //�ж������Ƿ�������ȷ���������������
        if (!(choic>=1&&choic<=9))
        {
            cout<<"�������Ŵ����˳�����"<<endl;
            break;

        }
        //��������ȷ��ŵ���Ϣ
        if((choic==7)|(choic==1)){
            b1=true;
            break;
        }
        //����9���˳�����
        if (choic==9)
        {
            cout<<"ͨѶ¼����ϵͳ�����˳�"<<endl;
            exit(0);

        }
        //��������ȷ���кţ���9��1����´���
        if(!b1){
            cout<<"�����ǵ�һ�ν���ͨѶ¼ϵͳ�������ͨѶ¼��Ա��Ϣ¼�룡��"<<endl;
            cout<<"�Ƿ���Ҫ¼���Ա��Ϣ(y/n)��";
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
        //��ȷ�ҷǵ�һ�ν���
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
            cout<<"������Ҫ���³�Ա��Ϣ��ΨһID��";
            cin>>temp;
            List.updateMenber(temp);
            break;
        case 4:
            char temp_id[20];
            cout<<"������Ҫ���³�Ա��Ϣ��ΨһID��";
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
    cout<<"�Ƿ�Ҫ������������(y/n)?"<<endl;
    ch='n';
    cin>>ch;
    cout<<ch<<endl;
    cout<<endl;//����
    if (ch=='Y'||ch=='y')
    {
        goto menu;
    }
    exit(1);
    return 0;
}