/// <reference path="C:\Users\Pedraza_Gang\Documents\Visual Studio 2015\Projects\Humberto_Pedraza\Humberto_Pedraza\Views/Resume/resume.html" />
/// <reference path="C:\Users\Pedraza_Gang\Documents\Visual Studio 2015\Projects\Humberto_Pedraza\Humberto_Pedraza\Views/Resume/resume.html" />


$('#resumeLink').on("click", function () {
    var url = $("#resume").data('url');
    $.get(url, function (data) {
  
        $("#resumeBody").html(data);

        $("#resume").modal('show');

    });

});


$('#modalAndroidSS').on("click", function () {
    var url = $("#displayAndroidSS").data('url');
    $.get(url, function (data) {

        $("#androidBody").html(data);

        $("#displayAndroidSS").modal('show');

    });

});

$('#modalCone').on("click", function () {
    var url = $("#displayCOne").data('url');
    $.get(url, function (data) {

        $("#ConeBody").html(data);

        $("#displayCOne").modal('show');

    });

});



$('#modalCtwo').on("click", function () {
    var url = $("#displayCtwo").data('url');
    $.get(url, function (data) {

        $("#CtwoBody").html(data);

        $("#displayCtwo").modal('show');

    });

});



$('#modalRDB').on("click", function () {
    var url = $("#displayRDB").data('url');
    $.get(url, function (data) {

        $("#rdbBody").html(data);

        $("#displayRDB").modal('show');

    });

});


$('#modalAnt').on("click", function () {
    var url = $("#displayAnt").data('url');
    $.get(url, function (data) {

        $("#antBody").html(data);

        $("#displayAnt").modal('show');

    });

});


$('#modalFit').on("click", function () {
    var url = $("#displayFit").data('url');
    $.get(url, function (data) {

        $("#fitBody").html(data);

        $("#displayFit").modal('show');

    });

});


$('#modalQ').on("click", function () {
    var url = $("#displayQ").data('url');
    $.get(url, function (data) {

        $("#qBody").html(data);

        $("#displayQ").modal('show');

    });

});


$('#modalGA').on("click", function () {
    var url = $("#displayGA").data('url');
    $.get(url, function (data) {

        $("#gaBody").html(data);

        $("#displayGA").modal('show');

    });

});


// transform on click

// -------------------------- Card Flip on button control --------------------- //
//-- Flip effect first then change panel positioning --//
$(".front").on('click', function () {

    setTimeout(function () {
        $(this).css('position', 'absolute'); //front
        var back = $(this);
        back = back.next('.back');

        back.css('position', 'static'); // back
    }, 165);
    var flipper = $(this).parent();
    var flipContainer = $(this).parent().parent();
       flipper.css('transform', 'rotateY(180deg)');
        flipContainer.css('.flip-container').css('transform', 'rotateY(180deg)');
   
});



$(".back").on("click", function () {

    setTimeout(function () {
        var front = $(this);
        front = front.prev();
        $(this).css('position', 'absolute');
        front.css('position', 'static');
    }, 165);
    var flipper = $(this).parent();
    var flipContainer = $(this).parent().parent();
    flipper.css('transform', 'rotateY(0deg)');
    flipContainer.css('transform', 'rotateY(0deg)');

});

// ---------------------------- End of card flip controls ---------------------- //