<div align="center">

# Cenarius 后面称之为 `CC`

<div align="left">

塞纳留斯Cenarius暴雪娱乐知名游戏系列《魔兽》的背景故事中的角色之一，主要出现在《魔兽争霸3》和《魔兽世界》及《炉石传说》中.
塞纳留斯是艾泽拉斯的自然生命精华，荒野众神之一，也是魔兽世界中最主要的荒野众神。其身世直到现在也是一个谜，在暗夜精灵的传说中他是艾露恩与玛洛恩所诞下的嫡子.

## 进度

目前还在开发中，还不能够用以商业化产品中。 之所以这么早就准备了技术开源，主要是为了使用github来记录开发流程和整个过程中的思考。

## 编译

项目整体都是依赖ruki的xmake编译工具，项目稳定后会提供稳定的编译方案。

## 计划和目标

鄙人之前已经开发过2个类似于微信小游戏底层runtime的项目，但是都有公司的版权。 于是为了能够提供给社区一个没有版权隐患的版本，所以我从新启动了这样一个项目。

这个项目也是我汲取了之前项目中的设计和犯下的错误而综合得到的架构，也是在深度研究了Chrome底层渲染优化策略后的一个版本(目前市面上面所有的小游戏runtime都是实现了webgl和canvas的标准，但是性能都比chrome差很多)。 这个版本内我会重点完成对canvas和webgl1的实现，并重点对tbr架构GPU做性能优化。 力求做到行业第一的渲染性能。 同时也保证最少支持iOS和Android系统。 如果我有足够的时间还会补充上面 Windows和Mac甚至Linux的实现(其实从家架构上几乎是完全的平台无关的，只是不同平台porting的工作而已)。

所有的代码都是开源的，目前还在开发中所以使用的GPL协议。 不建议入坑，项目稳定后我可能会修改开源协议。 这将是一个我会长期稳定维护的项目。

## License

目前是GPL协议，稳定后会修改成更加友好的开源协议。 个人开发者或者小公司(dau 50w以下的项目)可以直接用于商业项目中。 

## 联系方式(微信，用以提供长久的技术支持)

<img src="./doc/doc-image/wechat-image.jpg" width = "200" height = "200"/>
