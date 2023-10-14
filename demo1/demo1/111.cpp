#include <iostream>
#include <string>
using namespace std;
#define MAX 1000

//联系人结构体
struct person {
    /* data */
    string m_Name;
    int m_sex;
    int m_Age;
    string m_Phone;
    string m_Address;
};

//通讯录结构体
struct Addressbooks 
{
    struct person personArray[MAX];
    int m_Size;//当前通讯录中的联系人数目
};
//菜单界面


void showMenu() {
    cout<< "1、添加联系人" << endl;
    cout<< "2、显示联系人" << endl;
    cout<< "3、删除联系人" << endl;
    cout<< "4、查找联系人" << endl;
    cout<< "5、修改联系人" << endl;
    cout<< "6、清空联系人" << endl;
    cout<< "0、退出通讯录" << endl;
}

void addPerson(Addressbooks *abs) {
    //判断通讯录是否已满
    if(abs->m_Size == MAX) {
        cout << "通讯录已满！" << endl;
        return;
    }
    else {
    string name;
    cout << "请输入姓名" <<endl;
    cin >> name;
    abs->personArray[abs->m_Size+1].m_Name =name;
    cout << "请输入性别" <<endl;
    cout << "1---男" <<endl;
    cout << "2---女" <<endl;
    int sex = 0;
    while(true) {
        cin >>sex;
        if (sex == 1 || sex == 2) {
            abs->personArray[abs->m_Size+1].m_sex = sex;
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }
    cout << "请输入手机号" <<endl;
    string phone;
    cin >> phone;
    abs->personArray[abs->m_Size+1].m_Phone = phone;
    cout << "请输入地址" <<endl;
    string address;
    cin >> address;
    abs->personArray[abs->m_Size+1].m_Address = address;
    cout << "请输入年龄" <<endl;
    int age = 0;
    cin >> age;
    abs->personArray[abs->m_Size+1].m_Age = age;
    abs->m_Size++;
    cout << "添加成功！" << endl;
    }
}

void showallPerson(Addressbooks abs) {
    if(abs.m_Size == 0) {
        cout << "通讯录为空！" << endl;
    }
    else {
        for(int i = 1; i <= abs.m_Size; i++ ) {
        cout << "姓名："<< abs.personArray[i].m_Name << endl;
        cout << "年龄："<< abs.personArray[i].m_Age << endl;
        abs.personArray[i].m_sex == 1 ? cout << "性别：男" << endl : cout << "性别：女" << endl;
        cout << "手机号："<< abs.personArray[i].m_Phone << endl;
        cout << "居住地址："<< abs.personArray[i].m_Address << endl;
    }
    }
}

void deleteperson(Addressbooks *abs) {
    string name;
    cout << "请输入要删除的联系人名" << endl;
    cin >> name;
    int index = -1;
    for(int i = 1; i <= abs->m_Size; i++) {
        if(abs->personArray[i].m_Name == name) {
            index = i;
        }
    }
    if(index == -1) {
        cout << "通讯录中无该联系人" << endl;
    }
    else {
        for(int i = index; i < (abs->m_Size); i++) {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
    }
}

void findperson(Addressbooks *abs) {
    string name;
    cout << "请输入要查找的联系人名" << endl;
    cin >> name;
    int index = -1;
    for(int i = 1; i <= abs->m_Size; i++) {
        if(abs->personArray[i].m_Name == name) {
            index = i;
        }
    }
    if(index == -1) {
        cout << "通讯录中无该联系人" << endl;
    }
    else {
        cout << "姓名："<< abs->personArray[index].m_Name << endl;
        cout << "年龄："<< abs->personArray[index].m_Age << endl;
        abs->personArray[index].m_sex == 1 ? cout << "性别：男" << endl : cout << "性别：女" << endl;
        cout << "手机号："<< abs->personArray[index].m_Phone << endl;
        cout << "居住地址："<< abs->personArray[index].m_Address << endl;
    }
}

void modiperson(Addressbooks *abs) {
    string name;
    cout << "请输入要修改的联系人名" << endl;
    cin >> name;
    int index = -1;
    for(int i = 1; i <= abs->m_Size; i++) {
        if(abs->personArray[i].m_Name == name) {
            index = i;
        }
    }
    if(index == -1) {
        cout << "通讯录中无该联系人" << endl;
    }
    else {
        string name;
    cout << "请输入姓名" <<endl;
    cin >> name;
    abs->personArray[index].m_Name =name;
    cout << "请输入性别" <<endl;
    cout << "1---男" <<endl;
    cout << "2---女" <<endl;
    int sex = 0;
    while(true) {
        cin >>sex;
        if (sex == 1 || sex == 2) {
            abs->personArray[index].m_sex = sex;
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }
    cout << "请输入手机号" <<endl;
    string phone;
    cin >> phone;
    abs->personArray[index].m_Phone = phone;
    cout << "请输入地址" <<endl;
    string address;
    cin >> address;
    abs->personArray[index].m_Address = address;
    cout << "请输入年龄" <<endl;
    int age = 0;
    cin >> age;
    abs->personArray[index].m_Age = age;
    cout << "修改成功！" << endl;
    }
}

void clearall(Addressbooks *abs) {
    abs->m_Size = 0;
    cout << "通讯录已清空" <<endl;
}

int main(){

    //创建通讯录的结构体变量
    Addressbooks abs;

    //初始化通讯录中当前人员个数
    abs.m_Size = 0;

    int select = 0; //创建用户选择输入的变量
    while(true) {
        showMenu();

        cin >> select;
        switch(select) {
            case 1://1、添加联系人
                addPerson(&abs); //传入地址才能真正修改形参
                break;
            case 2://2、显示联系人
                showallPerson(abs);
                break;
            case 3://3、删除联系人
                deleteperson(&abs);
                break;
            case 4://4、查找联系人
                findperson(&abs);
                break;
            case 5://5、修改联系人
                modiperson(&abs);
                break;
            case 6://6、清空联系人
                clearall(&abs);
                break;
            case 0://0、退出通讯录
                cout << "欢迎下次使用" <<endl;
                system("pause");
                return 0;
                break;
            default:
                break;
        }

    }

    system("pause");
    return 0;
}
