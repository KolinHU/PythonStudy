#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# 功能：获取全国各市邮政编码 
# 时间：2018-3-23

import requests
import sys
import os
from html.parser import HTMLParser

class MyHTMLParser(HTMLParser):  
    a_text = False  
    def __init__(self):   
        HTMLParser.__init__(self)   
        self.data = []  

    def handle_starttag(self,tag,attr):  
        if tag == 'a': 
            self.a_text = True  
              
    def handle_endtag(self,tag):  
        if tag == '/a':  
            self.a_text = False  
              
    def handle_data(self,data):  
        if self.a_text:  
            self.data.append(data)  


# 截取Html源码片段
def CutHtml(content,str1,str2):
    start = content.find(str1)
    end = content.find(str2)
    content = content[start:end + len(str2)].strip()
    return content

# 获取Html
def Get_City_PostCode(url):
    # 获取网页源码
    content=requests.get(url).content.decode('gb2312')
   
    content=CutHtml(content,'<center><h2><div>江苏省邮编区号大全','<div align="center">')
    content=CutHtml(content,'<table cellpadding','</table>')

    # 解析数据
    hp = MyHTMLParser()   
    hp.feed(content)   
    hp.close()   

    with open(str(sys.path[0])+'\CityPostCode1.txt','w') as f:
        f.write(str(hp.data))

if __name__=='__main__':
    Get_City_PostCode('http://www.ip138.com/21')

print('all done!')    