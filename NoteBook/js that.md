## Javascript中的```var that=this```

> 之前看别人JS代码时也经常看到这么一句： ```var that = this```，但以前不以为然，直到自己遇到了才是真的坑，在这里记录一下。

在JavaScript中，this代表的是当前对象。

var that=this就是将当前的this对象复制一份到that变量中。这样做有什么意义呢？

	$('#content').click(function(){
	//this是被点击的#content
	var that = this;
	$('.content').each(function(){
	//this是.content循环中当前的对象
	//that仍然是刚才被点击的#content
	});
	});


可以看到，this对象在程序中随时会改变，而```var that=this```之后，that没改变之前仍然是指向当时的this，这样就不会出现找不到原来的对象.