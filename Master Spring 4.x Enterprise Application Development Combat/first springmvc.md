## Study SpringMVC
###
> This is a tutorial on creating your first springmvc project

#### What you need?

* Eclipse
* Tomcat
* JDK
* Spring-framework

### 新建项目

* 打开Eclipse
* File-New-Other
* 选择Dynamic web project

![](http://images2015.cnblogs.com/blog/619240/201608/619240-20160821181710870-1612376182.png)

工程建立后，目录结构如下：

![](http://images2015.cnblogs.com/blog/619240/201608/619240-20160821181843964-843239775.png)

### 导入jar包

* spring-aop-4.0.4.RELEASE.jar
* spring-beans-4.0.4.RELEASE.jar
* spring-context-4.0.4.RELEASE.jar
* spring-core-4.0.4.RELEASE.jar
* spring-expression-4.0.4.RELEASE.jar
* spring-web-4.0.4.RELEASE.jar
* spring-webmvc-4.0.4.RELEASE.jar
* commons-logging-1.1.1.jar（用来打印log）

在WEB-INF目录下新建lib文件夹，并将上面的jar包放入其中。

### 配置文件及编写代码

##### web.xml（WEB-INF下）

	<?xml version="1.0" encoding="UTF-8"?>
	<web-app xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xmlns="http://java.sun.com/xml/ns/javaee"
    xsi:schemaLocation="http://java.sun.com/xml/ns/javaee http://java.sun.com/xml/ns/javaee/web-app_2_5.xsd"
    id="WebApp_ID" version="2.5">
    
    <!-- 配置DispatchcerServlet -->
    <servlet>
        <servlet-name>springDispatcherServlet</servlet-name>
        <servlet-class>org.springframework.web.servlet.DispatcherServlet</servlet-class>
        <!-- 配置Spring mvc下的配置文件的位置和名称 -->
        <init-param>
            <param-name>contextConfigLocation</param-name>
            <param-value>classpath:springmvc.xml</param-value>
        </init-param>
        <load-on-startup>1</load-on-startup>
    </servlet>
    
    <servlet-mapping>
        <servlet-name>springDispatcherServlet</servlet-name>
        <url-pattern>/</url-pattern>
    </servlet-mapping>
    
</web-app>

##### Springmvc.xml（scr下）
在src目录下新建springmvc.xml

	<?xml version="1.0" encoding="UTF-8"?>
	<beans xmlns="http://www.springframework.org/schema/beans"
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xmlns:context="http://www.springframework.org/schema/context"
    xmlns:mvc="http://www.springframework.org/schema/mvc"
    xsi:schemaLocation="http://www.springframework.org/schema/beans http://www.springframework.org/schema/beans/spring-beans.xsd
        http://www.springframework.org/schema/context http://www.springframework.org/schema/context/spring-context-4.0.xsd
        http://www.springframework.org/schema/mvc http://www.springframework.org/schema/mvc/spring-mvc-4.0.xsd">
        
        
        <!-- 配置自动扫描的包 -->
        <context:component-scan base-package="com.jackie.springmvc"></context:component-scan>
        
        <!-- 配置视图解析器 如何把handler 方法返回值解析为实际的物理视图 -->
        <bean class="org.springframework.web.servlet.view.InternalResourceViewResolver">
            <property name = "prefix" value="/WEB-INF/views/"></property>
            <property name = "suffix" value = ".jsp"></property>
        </bean>
	</beans>


##### HelloWorld.java（com.jackie.springmvc下）

	package com.jackie.springmvc;

	import org.springframework.stereotype.Controller;
	import org.springframework.web.bind.annotation.RequestMapping;
	
	@Controller
	public class HelloWorld {
	
	    /**
	     * 1. 使用RequestMapping注解来映射请求的URL
	     * 2. 返回值会通过视图解析器解析为实际的物理视图, 对于InternalResourceViewResolver视图解析器，会做如下解析
	     * 通过prefix+returnVal+suffix 这样的方式得到实际的物理视图，然后会转发操作
	     * "/WEB-INF/views/success.jsp"
	     * @return
	     */
	    @RequestMapping("/helloworld")
	    public String hello(){
	        System.out.println("hello world");
	        return "success";
	    }
	}

##### index.jsp（WebContent下）

在新建success.jsp之前，我们需要有一个入口，也就是这里的index.jsp

	<%@ page language="java" contentType="text/html; charset=UTF-8" 
	pageEncoding="UTF-8"%>
	<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
	<html>
	<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<title>Insert title here</title>
	</head>
	<body>
	
	<a href="helloworld">hello world</a>
	
	</body>
	</html>

##### success.jsp（WEB-INF/views下）

该页面是作为请求成功后的相应页面

	<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
	<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
	<html>
	<head>
	<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
	<title>Insert title here</title>
	</head>
	<body>
	
	<h4>Success Page</h4>
	
	</body>
	</html>


### 额外配置问题

##### Tomcat服务器的添加

从前面的介绍可以看出，我们的程序是通过浏览器发请求来获取想要的页面，那么这里就免不了要有一个web服务器，这里就是tomcat。

1. 首先你需要下载个tomcat，然后在eclipse->Window->Preferences->Server中绑定这个本地下载的tomcat服务器
2. 其次你需要在你新建的spring mvc项目中添加tomcat的支持，否则在新建的jsp文件中会提示报错“The superclass javax.servlet.http.HttpServlet was not found on the Java Build Path”，右键项目->Properties->Java Build Path->Libraries->Add Library->Server Runtime, 选择你的tomcat即可

![](http://images2015.cnblogs.com/blog/619240/201608/619240-20160821190148714-164875807.png)

有了tomcat服务器，你就可以在工程上右键Run As->Run on Server,选择你的tomcat服务器，这样就可以启动tomcat服务，帮助你完成网页的请求和响应操作。



具体请参考 ： [学习SpringMVC——从HelloWorld开始](http://www.cnblogs.com/bigdataZJ/p/springmvc1.html)