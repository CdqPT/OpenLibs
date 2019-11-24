//
//  main.cpp
//  iniTest
//
//  Created by 陈德强 on 2019/11/24.
//  Copyright © 2019 陈德强. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <cstdio>
#include "iniLoader.h"

int main(){
    cdq::IniFile iniTest;
    
    if(!iniTest.read("~/test.ini"))
    {
        std::cout<<"No files!"<<std::endl;
        return 0;
    }
    
    // 转储整数
    {
        int t1 = 9999, t2 = 9999;
        iniTest.write("a.b.c1", t1);
        iniTest.write("a.b.c4", t2, true);
        printf("a.b.c1 = %d\na.b.c4 = %d\n", t1, t2);
    }
    
    // 转储浮点数
    {
        float t1 = 0.0;
        iniTest.write("a.b.c2", t1);
        printf("a.b.c2 = %f\n", t1);
    }
    
    // 转储字符串
    {
        char t1[32] = {0};
        std::string t2, t3 = "0000000000000000";
        std::string t4, t5;
        
        iniTest.write("d.c.b.a.e.f1", t2); // 字符串
        iniTest.write("d.c.b.a.e.f1", t3.begin(), t3.end()); // 字符串迭代器
        iniTest.write("d.c.b.a.e.f2", t1); // 字符串
        iniTest.write("d.c.b.a.e.f2", t1 + 16, t1 + 32); // 字符串指针迭代器
        iniTest.write("a.b.c3", t4); // 带不可打印字符的字符串
        iniTest.write("d.c.b.a.e.f3", t5); // 字符串 - Section使用.分割层级
        
        printf("len(t2) = %d\nlen(t3) = %d\n", (int)t2.size(), (int)t3.size());
        printf("d.c.b.a.e.f2 = %s\n", t1);
        printf("d.c.b.a.e.f2 = %s(+16)\n", t1 + 16);
        printf("d.c.b.a.e.f3 = %s\n", t5.c_str());
        printf("a.b.c3 = %s\n", t4.c_str());
    }
    
    // 转储到 vector
    {
        std::vector<std::string> t1;
        std::list<bool> t2;
        iniTest.write("a.arr", t1);
        iniTest.write("a.bool", t2);
        
        for (size_t i = 0; i < t1.size(); ++i) {
            printf("t1[%d] = %s\n", (int)i, t1[i].c_str());
        }
        
        size_t index = 0;
        for (std::list<bool>::iterator iter = t2.begin(); iter != t2.end(); ++iter) {
            printf("t2[%d] = %s\n", (int) index ++, (*iter) ? "true" : "false");
        }
        
    }
    
    // 转储时间周期
    {
        cdq::duration dur;
        iniTest.write("system.interval_ns", dur, true);
        printf("system.interval_ns: sec %lld, nsec: %lld\n", static_cast<long long>(dur.sec), static_cast<long long>(dur.nsec));
        iniTest.write("system.interval_us", dur, true);
        printf("system.interval_us: sec %lld, nsec: %lld\n", static_cast<long long>(dur.sec), static_cast<long long>(dur.nsec));
        iniTest.write("system.interval_ms", dur, true);
        printf("system.interval_ms: sec %lld, nsec: %lld\n", static_cast<long long>(dur.sec), static_cast<long long>(dur.nsec));
        iniTest.write("system.interval_s", dur, true);
        printf("system.interval_s: sec %lld, nsec: %lld\n", static_cast<long long>(dur.sec), static_cast<long long>(dur.nsec));
        iniTest.write("system.interval_m", dur, true);
        printf("system.interval_m: sec %lld, nsec: %lld\n", static_cast<long long>(dur.sec), static_cast<long long>(dur.nsec));
        iniTest.write("system.interval_h", dur, true);
        printf("system.interval_h: sec %lld, nsec: %lld\n", static_cast<long long>(dur.sec), static_cast<long long>(dur.nsec));
        iniTest.write("system.interval_d", dur, true);
        printf("system.interval_d: sec %lld, nsec: %lld\n", static_cast<long long>(dur.sec), static_cast<long long>(dur.nsec));
        iniTest.write("system.interval_w", dur, true);
        printf("system.interval_w: sec %lld, nsec: %lld\n", static_cast<long long>(dur.sec), static_cast<long long>(dur.nsec));
    }
    
    return 0;
}
