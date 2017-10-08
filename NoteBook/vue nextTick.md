## Vue的nextTick函数

之前一直不太懂vue中的数据驱动视图这个原理

这里简单验证下vue中nextTick这个函数的作用

	<!DOCTYPE html>
	<html>
	<head>
    <title></title>
    <script type="text/javascript" src="vue.js"></script>
	</head>
	<body>
	<div id="example">
	    {{message}}
	</div>
	 <script type="text/javascript">
	            var vm = new Vue({
	              el: '#example',
	              data: {
	                message: '123'
	              }
	            })
	            console.log(vm.$el.textContent)  // 123
	            vm.message = 'new message' // 更改数据
	            console.log(vm.$el.textContent)  //123
	            Vue.nextTick(function () {
	              console.log(vm.$el.textContent)
	              vm.$el.textContent === 'new message' // new message
	            })
	            vm.$el.textContent === 'new message' // false
	            console.log(vm.$el.textContent)  // 123
	            
	    </script>
	</body>
	</html>

一般对于选择dom标签并对dom树作操作的函数要写在nextTick函数里才会生效