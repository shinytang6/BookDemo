$(document).ready(function(){
   $("a.tooltip").mouseover(function(event){
    var tooltip="<div id='tooltip'>"+this.title+"</div>";
    $("body").append(tooltip);
    $("#tooltip").css({
        "top":event.pageY+"px",
        "left" :event.pageX+"px"
    }).show("fast")
   })
    .mouseout(function(){
        $("#tooltip").remove();
    })

});