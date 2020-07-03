$(document).ready(function() {
  
   $("#add").click(function() {
      var html = "";
      html += "<li>";
      html += '<input type="button" class="delete" value="Task Complete">';
      html += "<p>" + $("#task").val() + "</p>";
      html += "</li>";
      $("ul").append(html);

      // attach listener to newwly added task
      $(".delete").click(function(e) {
         e.target.parentElement.remove();
      });
      $("#task").val("");
   }); // end click
  
   $(".delete").click(function(e) {
      e.target.parentElement.remove();
   }); // end click
}); // end ready