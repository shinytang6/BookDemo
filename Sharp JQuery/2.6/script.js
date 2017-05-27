$(document).ready(function(){

var $category=$("ul li:gt(5):not(:last)");   //获取索引值大于5的品牌集合对象(除去最后一条)
$category.hide();  //隐藏上述JQuery 对象

var $toggleBtn=$("div.show >a");
$toggleBtn.click(function(){
    if($category.is(":hidden")){       //如果元素隐藏则显示，对应的是:visible
    $category.show();          
    $(".show a").text("精简显示品牌")  //改变按钮的文本
    return false
    }
    else{
    $category.hide();
    $(".show a").text("显示全部品牌")
    return false
    }
})
});
