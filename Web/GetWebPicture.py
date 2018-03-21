# 爬取网页
# import requests
# # r = requests.get('https://book.douban.com/&format=json') # 豆瓣首页
# r = requests.get('https://www.douban.com/search', params={'q': 'python', 'cat': '1001'})
# with open('test.txt', 'w',encoding='utf-8') as f:
#     f.write(r.text)
#     print('Done')

# 爬取网页图片
import requests
import json
import urllib

def getSogouImag(category,length,path):
    n = length
    cate = category
    imgs = requests.get('http://pic.sogou.com/pics/channel/getAllRecomPicByTag.jsp?category='+cate+'&tag=%E5%85%A8%E9%83%A8&start=0&len='+str(n))
    jd = json.loads(imgs.text)
    jd = jd['all_items']
    imgs_url = []
    for j in jd:
        imgs_url.append(j['bthumbUrl'])
    m = 0
    for img_url in imgs_url:
            print('***** '+str(m)+'.jpg *****'+'   Downloading...')
            urllib.request.urlretrieve(img_url,path+str(m)+'.jpg')
            m = m + 1
    print('Download complete!')

getSogouImag('壁纸',10,'C:/Users/hlc24/Desktop/PythonStudy/data/pic/')