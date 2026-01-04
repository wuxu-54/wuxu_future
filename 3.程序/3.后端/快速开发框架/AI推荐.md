# 开源免费Web后台快速开发框架/工具

1. **RuoYi（若依，核心单体版）**
    - 开源协议：MIT（宽松协议，可自由用于商业项目，无附加约束，可二次分发修改）
    - 核心特点：单体架构为主，支持两种部署模式（前后端分离：Spring Boot + Vue 2/Element UI；单体集成：Spring Boot + Thymeleaf），功能聚焦后台核心基建无冗余，内置用户/角色/权限/菜单/代码生成器、数据字典、日志监控等核心功能。
    - 适用场景：新手入门后台开发、中小型单体项目快速落地、需要低成本二次开发的业务系统。
    - 学习成本：低
    - 开源地址：Gitee：<https://gitee.com/y_project/RuoYi；GitHub：https://github.com/yangzongzhuan/RuoYi>

2. **Jeecg Boot（杰思奇，低代码标杆）**
    - 开源协议：Apache License 2.0（商业友好，保留版权声明即可用于商业项目）
    - 核心特点：低代码开发框架，支持单体/微服务架构，前后端分离（Spring Boot + Vue 3/Element Plus），内置可视化表单设计器、流程设计器、报表生成器、多租户，生态丰富，覆盖多行业解决方案，代码生成能力远超传统框架。
    - 适用场景：中大型项目、快速迭代的业务系统、需要低代码提效的团队、多租户SaaS平台。
    - 学习成本：中
    - 开源地址：Gitee：<https://gitee.com/jeecg/jeecg-boot；GitHub：https://github.com/jeecgboot/jeecg-boot>

3. **Pig（猪哥，微服务云原生框架）**
    - 开源协议：Apache License 2.0（商业友好，可用于商业项目，需保留版权声明）
    - 核心特点：微服务云原生架构，基于Spring Cloud Alibaba + Vue 2/Element UI构建，聚焦云原生落地，支持K8s部署、服务网格、分布式事务、灰度发布、全链路监控，功能完善且架构规范，生态配套齐全。
    - 适用场景：大型分布式云原生项目、高可用高并发业务系统、需要容器化部署的企业级项目。
    - 学习成本：高
    - 开源地址：Gitee：<https://gitee.com/log4j/pig；GitHub：https://github.com/pig-mesh/pig>

4. **ELadmin（E佬，轻量优雅后台框架）**
    - 开源协议：MIT（宽松协议，商业项目无附加约束，可自由修改分发）
    - 核心特点：轻量单体架构，前后端分离（Spring Boot + Vue 2/Element UI），代码优雅规范，内置用户/角色/权限/菜单/代码生成器、定时任务、文件上传、数据导出，无冗余依赖，部署简单，支持多环境配置。
    - 适用场景：中小型单体项目、追求代码优雅性的团队、快速落地的轻量业务系统。
    - 学习成本：低
    - 开源地址：Gitee：<https://gitee.com/elunez/eladmin；GitHub：https://github.com/elunez/eladmin>

5. **BladeX（刀锋，微服务/单体双模框架）**
    - 开源协议：Apache License 2.0（商业友好，可用于商业项目，需保留版权声明）
    - 核心特点：支持单体/微服务双模架构，基于Spring Boot/Spring Cloud Alibaba + Vue 2/Element UI构建，生态丰富，内置代码生成器、工作流、分布式事务、分库分表，提供丰富的插件和扩展组件，二次开发灵活性高。
    - 适用场景：中大型项目、需要灵活切换架构的业务系统、对扩展插件有需求的团队。
    - 学习成本：中高
    - 开源地址：Gitee：<https://gitee.com/bladejava/BladeX；GitHub：https://github.com/bladejava/BladeX>

6. **MineAdmin（PHP生态，后台快速开发框架）**
    - 开源协议：MIT（宽松协议，商业项目无附加约束，可自由修改分发）
    - 核心特点：PHP生态框架，基于ThinkPHP 6 + Vue 3/Element Plus构建，前后端分离，内置用户/角色/权限/菜单/代码生成器、多租户、可视化表单设计，专为PHP开发者打造，部署简单，生态贴合PHP技术栈。
    - 适用场景：PHP技术栈的中小型到中大型项目、PHP开发者快速落地后台系统、SaaS多租户平台。
    - 学习成本：中（针对PHP技术栈开发者，Java开发者学习成本高）
    - 开源地址：Gitee：<https://gitee.com/mineadmin/MineAdmin；GitHub：https://github.com/mineadmin/MineAdmin>

## 三、 开源免费避坑补充

1. 所有工具核心功能（后台基建、代码生成、权限管理等）均在开源仓库提供，无阉割，无需付费解锁
2. 协议优先级（商业项目优先选择）：MIT > Apache 2.0 > GPL
3. 阿里系工具无商业陷阱，开源版组件已满足大部分项目需求，无需依赖阿里云商用服务
4. 均可在Gitee/GitHub下载源码，社区提供完整部署文档和使用教程
