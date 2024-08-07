# 电动小台钳



## 项目介绍

本项目使用CNC板材及一些机械零件制作了一个电动焊接台钳。CNC器件在嘉立创1元CNC打样活动打样，驱动部分使用闭环步进驱动，电机驱动板适用35步进电机。可用于其他项目。计划实现功能

+ 台钳位置闭环

+ 按键设定位置

+ 夹持电流自动调整(待做)

+ 长时间自动休眠(待做)

+ 外面控制输入(待做)



![image](https://github.com/0XIAOMAO0/STEP_MR_VISE/tree/master/software/渲染图.jpg)

![image](https://github.com/0XIAOMAO0/STEP_MR_VISE/tree/master/software/台钳手动版.JPG)








视频演示：[bilibili](https://www.bilibili.com/video/BV1ybicebESk/?share_source=copy_web&vd_source=d128331ee99153cf5294c26aba5f51e4) 

软件开源地址：[github](https://github.com/0XIAOMAO0/STEP_MR_VISE)   软件部分参考["矛盾聚合体"](https://gitee.com/STM32G474RET6/cl-stepper-motor)  

硬件开源地址: [oshwhub](http://oshwhub.com/xaiomao/tai-qian-kong-zhi-ban)硬件部分参考["HyperStepper"](https://oshwhub.com/HyperCNC/yi-ti-hua-di-cheng-ben-gao-su-gao-jing-du-quan-bi-huan-bu-jin-dian-ji)



## 材料清单 

1.电路板所需元器件BOM已给出

2.结构部分：

|编号| 名称                         | 个数 | 链接     |
|-|--------------------------- | ---- | ------------- |
| 1 |CNC铝板                      | 3    | 嘉立创CNC打样 |
| 2 |2020铝型材120mm两端攻牙M6    | 2    | [参考连接]([欧标2020工业铝型材2040/2060/2080V槽黑色铝合金型材3D打印框架-淘宝网 (taobao.com)](https://item.taobao.com/item.htm?spm=a1z09.2.0.0.56772e8d9V2iT5&id=679620555797&_u=72dvq808b1ad&pisk=fmJqm_vpCxH2sudGza6N4FA1PXWAL93ISd_1jhxGcZbm6iMgQh-hfm3tDQSM5UntDttG7F85yRssMVewzEtHGsT6GNjGrUxbhNMA_F-BJFwsHIsgQUtOsF9wXRSMjFnA5mhWDnBOI2gCQvtvDwjORCpVSgbk2GQgi0dmIBXOI2gaNRfxLOLCxFdru_mPfGwGSFb0qTbRfG2DSZfurMSdINYGI0WlbMFGm-jcrTjsGW7GR8SFiDRMpGh4Du1c-nbDcU9oW_Nvca-9ALj24w-0XR2MUi52Cr9L38fXsHCphnMaetteZTj2Sv0cEHAyAsJq8-_O_L82_Ei_6gRwjpBALlDD4t7VtK5YXJ8H4hACaLinptWcoC6vfkuX4K8XDL-_j7XVhQ5e39DLoNOWYdSwBVHy8nAHSCSPgPIl9BJ9gPVNigIPR0ouhsYAwUgNVZFT6sdR4wixD5FOigIPR0oz65CApg7IDmC..)) |
| 3 |8mm光轴130mm(两端不能有毛刺) | 2    | [参考链接]([45#钢直线导轨轴承20光轴镀铬棒加工高精度圆柱硬轴软轴活塞光杆-淘宝网 (taobao.com)](https://item.taobao.com/item.htm?id=707072898042&ft=t)) |
| 4 |双切边法兰直线轴承8x15x24    | 2    | [参考连接]([双切边椭圆法兰直线轴承中间型加长LMHC10 12 16 20 25 30 40 LUU-淘宝网 (taobao.com)](https://item.taobao.com/item.htm?spm=a1z09.2.0.0.56772e8d9V2iT5&id=674397062232&_u=72dvq80876ae&pisk=fabmm-OWVi-X-5hTnaYbXK5tyMr8hxT17O39BFpa4LJ71mnYGhRNsObOD1J9SOXGIKKahEQGE61TGNFXuPANpTYOMKpOE5XA1VebfE3ZIt1UhspTGNvwEtWMfS99QdXO_iF8JyCfGFTwIJULJYvr1wBm7mu4_LR6_gCqDX5fGF9ZwArd4sigsZ75uhWwz3RB_Fuw7VPk4CRe7q-Zu0kyFC8wQO-24YRHsxo23n8rGRE2hN7Pz-RGyraCYmb2inviWE0GdN0p4plwnV39nI-mMsJo7V7lVr_RsKrIwdTvh1OcCygXuhjVnQ8gS48chs7wqNe8Jnfe_OTAz5o2LiBvzZSn_V5koK-OlnM0Ep7fawTy2yPhaa6AGaft_PRRpL5fuF4UOEY23UA5W8g2IgSNknTs3-YNZCSyl0oe6au6a5Qrfct2NQvCYA_E1ZN4wCNuZDP60QOXp7Vofct2NQvLZ7mUcnRWGpC..&sku_properties=122276018:20213)) |
| 5 |T8丝杆143mm螺距2导程8        | 1                 | [参考连接]([铭泰3d打印机配件T型T8丝杆步进电机丝杠螺母梯形螺杆不锈钢导程8-淘宝网 (taobao.com)](https://item.taobao.com/item.htm?spm=a1z09.2.0.0.56772e8d9V2iT5&id=573812002249&_u=72dvq808d597&pisk=f4MtmaTXGeYM6EAmCcO3nM3O00t3HAnZYVo5nr4GG23Kk0IisS40G-3ryS6D_RVYH2anIPmgCoNjo4Gg5f4cHx3EWOX0CqvYl0le0PqiIiEjOVBmsc4i9ieZKfX0SFyxc42vrUvkEcoag-TkrAa_C6y72t1foS1CAa4OjQ9kEcodjltoALx4NMSuuowb1SZIAyr8c1gbGk9Q8orf5o66vDaUc-Z_GO1QduZRClNsGDIToGaAHjg-gNvHg361CvEBuRi92sUnFlB3rczpPeDdz5USfyBXr6l4GrUEFeAKY2csSkuveeeIVXe_Xq95ZyGKAAPueQ1tPD0ZeRMJWOq3MPhICWIfhDwUSScxWFCa5f0LakNCDLrnryiZCXKVRcguWRZQtLt-ASGnQ7kMROeSac2iG29dB4srzYDJpY_uyof6vHCVg5ZhNIBh-Ug6_PqLrHfhgsP3YkUkvHCVg5ZUvzxHEs54tk5..)) |
| 6 |微型法兰轴承F688Z（8*18 *5） | 手动:2 / 电动:1   | [参考连接]([铭泰 3D打印机配件 微型带法兰直线轴承 F623 624 604 625 688ZZ-淘宝网 (taobao.com)](https://item.taobao.com/item.htm?spm=a1z09.2.0.0.56772e8d9V2iT5&id=574092180169&_u=72dvq8081998&pisk=fMVKm4j5FGjh_n6uOy6iZFEpzr_ieWUU7kzXZ0mHFlET2rL3KYmoFbE4DYOlLXD-wligtD4nO4M7qownAJmkw7EavBAoOuf-VryNzD03tU37CkduKym3BUhUsJAoxMl8PocRmifciyzEUbscmWiIOdljz2tWq0G61nmp-t1ciyz9-2_05sbrh1ki44GSdYg_5cuxPpZSFCasb4uWA4OCWPiZPbgIFB9s1qgvO2MIGM8KqeiJw8ZYUHfM03RHt5314XadTLmTi2BqDymOcGV90vnbRcd5mdyrF0naGGXT7l2QxVrRMGh_lRhIJu1XncwT5WkmMt9LcPqUMXNAvB0ieDe_OALWNPGZxY28vMpEAJqt3VM6ysugmcaUORQyfyZmvXgsIs_Y5YwgTxPhfBhb3yc3Fl199osrTSVA6StmD4vCWNpyUvgMhTdMjiZCLD0tmNvMULki7VncWNpyUvgZWmbGiLJrIV5..&sku_properties=122276018:20213)) |
| 7 |消隙螺母T8导程8              | 1                 | [参考连接]([3D打印机配件T8丝杆切边螺母铜消间隙消回差螺母梯型不锈钢丝杆-淘宝网 (taobao.com)](https://item.taobao.com/item.htm?spm=a1z09.2.0.0.56772e8d9V2iT5&id=648455763916&_u=72dvq808be39&pisk=fQvEmQ9vFvHUMZOl7N6PbUA55jWdMt3jrL_5q3xlAwbnwMMuU3-cVD3-vCSkPFn-v9tlzU81W8sS94ey7etDO6TWOajlSFxQdaMdaU-XkUwSpBsuUFtRZU9y28SkqUndPDh6vHBREqgfUxtpvZjRlQpFxO2MXiSlxcdnEIXREqgz18fK3TLfmHCo81mNVgwlrUjhsRbOVWbkrwfgSiSAEaYlEcWG4iFlxJjhSOjSG77llRSVtmRkHghUjRf5oHbHAI9ioOFp0NSAmdIebNt3282kQM5eFy9YLRfBZnCvdHMzB9t2sOjerx0hInAwc6JEuJ_Rad8eaei7wGRyqKBd3uDHb97Fip5L2-8Db3Af_dimH9Wh-Q6pVouBbp8Bvd-7q5XFdC52LtDY-aO60LSye4HwuHADrQSz_zIGMIJJTzVPtGINlcogd6Yd6FgPfwF8w6dObZiKv7FRtGINlcoaw7CdHG7jvDC..)) |
| 8 |T8丝杆丝杆螺母螺距2导程8     | 1(一般买丝杆赠送) | [参考连接]([铭泰3d打印机配件T型T8丝杆步进电机丝杠螺母梯形螺杆不锈钢导程8-淘宝网 (taobao.com)](https://item.taobao.com/item.htm?spm=a1z09.2.0.0.56772e8d9V2iT5&id=573812002249&_u=72dvq808d597&pisk=f4MtmaTXGeYM6EAmCcO3nM3O00t3HAnZYVo5nr4GG23Kk0IisS40G-3ryS6D_RVYH2anIPmgCoNjo4Gg5f4cHx3EWOX0CqvYl0le0PqiIiEjOVBmsc4i9ieZKfX0SFyxc42vrUvkEcoag-TkrAa_C6y72t1foS1CAa4OjQ9kEcodjltoALx4NMSuuowb1SZIAyr8c1gbGk9Q8orf5o66vDaUc-Z_GO1QduZRClNsGDIToGaAHjg-gNvHg361CvEBuRi92sUnFlB3rczpPeDdz5USfyBXr6l4GrUEFeAKY2csSkuveeeIVXe_Xq95ZyGKAAPueQ1tPD0ZeRMJWOq3MPhICWIfhDwUSScxWFCa5f0LakNCDLrnryiZCXKVRcguWRZQtLt-ASGnQ7kMROeSac2iG29dB4srzYDJpY_uyof6vHCVg5ZhNIBh-Ug6_PqLrHfhgsP3YkUkvHCVg5ZUvzxHEs54tk5..)) |
| 9 |联轴器5*8                    | 手动:0 / 电动:1   | [参考连接]([铭泰3D打印机配件铝合金联轴器 电机车膜船航模联轴器金属模型DIY-淘宝网 (taobao.com)](https://item.taobao.com/item.htm?spm=a1z09.2.0.0.56772e8d9V2iT5&id=570850575149&_u=72dvq808218b&pisk=fOfsm710kcm11d_BmdUedseXWlOjhGNzMqTArZhZkCd9hjQNVEl23RYjGH_8Shy0Ii6CDMvwXnJ2GEsyxNl4SNzbGZQJXIWwbEIFcMDNbs-VYS_lVdlNksuGKg7-_1yMgjOMiIEz47PP7NADMGh9arnMvUYbgFhtBANC7yrz47PbB2dbfuW2eOYXAEtpWEKvMyGplUOvkFdYRHLXrxnODIUCJHYXkcLvBDhpkETtGKEB-RtO5ynTgyymgx7yAjhSrLpTZiMqtXc97dxJp3cvL6T6C3QOst8OweCFOLJEuuOdr9S9RQNj9C95BGTd-oGWXT7k9HIxfk8hBG1ph6z0Iw1XfLC9dqGl8BYADK63Vb86_9951O4mvNIyfTdGu4ZNRL6BEepKlAdNUa5De1FsqHJklgT5fcsrtb-7E0HjRLcXR3zQRxDql5CeaDS1e0J9-e5zRyisndLHR3zQRxDDBeYeLyaIfxf..)) |
| 10 |M6x14螺丝                    | 4                 |  |
| 11 |M3*12 *4(头径)小头螺丝       | 10                |  |
| 12 | 35步进电机 | 手动:0 / 电动:1 ||

