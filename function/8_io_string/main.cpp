/**************************************************************
* auther:   MarkWang
* date:     20190129
* desc: 函数重载,如果同一作用域内的几个函数名字相同但形参列表不同，我们称之为重载。
*
*
***************************************************************/
//marktest1
//marktest2
//marktest4

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Sales_data{
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;
    const double price1 = 1.0;
    double price2 = 1.0;
    double avg_price()const;
public:
    double change_price1()const;
    double change_price2();
   
};

double Sales_data::change_price2()
{
        price2 = 1.11;
        printf("%s %d price1: %f\n",__func__,__LINE__,price2);
        return price2;
}


double Sales_data::change_price1() const
{
        //price1 = 1.11;
//        change_price2();
// ././main.cpp:41:23: error: passing ‘const Sales_data’ as ‘this’ argument discards qualifiers [-fpermissive]
//          change_price2(); 
        printf("%s %d price1: %f\n",__func__,__LINE__,price1);
        return price1;
}

void update_camera_calibration_status()
{
    string s("./ADAS.stat");
    fstream fstrm(s);
    if(fstrm.is_open() == 0)
    {
        cout<<"status is NotCalibrated"<<endl;
        cout<< "fstrm open file failed"<<endl;
    }
    else
    {
        cout<<"fstrm open file success"<<endl;
    }
    string line;
    int pos = 0;
    while(getline(fstrm, line))
    {
        pos = line.find("ADASCalibrationStatus");
        cout<<"line:"<<line<<endl;
        cout<<"string pos:"<<pos<<endl;
        if(pos >= 0)
        {
            pos = line.find(':');
            cout<<": pos:"<<pos<<endl;
            string status = line.substr(pos+1);
            cout<<"status:"<<status<<endl;
            if(status.compare("Good")==0)
            {
                cout<<"status is Good"<<endl;
            }
            else if(status.compare("ExtrinsicXmlMissing")==0)
            {
                cout<<"status is ExtrinsicXmlMissing"<<endl;
            }
            else if(status.compare("IntrinsicXmlMissing")==0)
            {
                cout<<"status is IntrinsicXmlMissing"<<endl;
            }
            else if(status.compare("NotCalibrated")==0)
            {
                cout<<"status is NotCalibrated"<<endl;
            }
            else if(status.compare("unkown")==0)
            {
                cout<<"status is NotCalibrated"<<endl;
            }
            else
            {
                cout<<"status is NotCalibrated"<<endl;
            }
            break;


        }
    }

    
}


int main(int,char**)
{

    printf("****************************************************\n");

    update_camera_calibration_status();


    printf("****************************************************\n");

    return 0;
    
}


