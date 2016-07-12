
$(document).ready(function () {
    $("#welcomeMessage").hide().html("<strong>Welcome to my personal webpage</strong>").fadeIn(3000);

    if ($(window).width() < 500) {
        $('.carousel').carousel({
            interval: false
        });
    } else {
        $('.carousel').carousel({
            interval: 6000
        });
    }
    // Modal Contact Events
    var red_shadow_on = false;
    var first_time_shadow = true
    var red_shadow_on_subject = false;
    var first_time_shadow_subject = true;
    var red_shadow_on_email = false;
    var first_time_shadow_email = true;
    var red_shadow_on_message = false;
    var first_time_shadow_message = true;
    var danger_icon = "<i class='glyphicon glyphicon-remove-circle' id='nameDangerIcon'></i>";
    var success_icon = "<i class='glyphicon glyphicon-ok' id='nameSuccessIcon'></i>";
    var danger_icon_subject = "<i class='glyphicon glyphicon-remove-circle' id='subjectDangerIcon'></i>";
    var success_icon_subject = "<i class='glyphicon glyphicon-ok' id='subjectSuccessIcon'></i>";
    var danger_icon_email = "<i class='glyphicon glyphicon-remove-circle' id='emailDangerIcon'></i>";
    var success_icon_email = "<i class='glyphicon glyphicon-ok' id='emailSuccessIcon'></i>";
    var danger_icon_message = "<i class='glyphicon glyphicon-remove-circle' id='messageDangerIcon'></i>";
    var success_icon_message = "<i class='glyphicon glyphicon-ok' id='messageSuccessIcon'></i>";
    var danger_icon_added_for_nameFormGroup = false;
    var success_icon_added_for_nameFormGroup = false;
    var danger_icon_added_for_subjectFormGroup = false;
    var success_icon_added_for_subjectFormGroup = false;
    var danger_icon_added_for_emailFormGroup = false;
    var success_icon_added_for_emailFormGroup = false;
    var danger_icon_added_for_messageFormGroup = false;
    var success_icon_added_for_messageFormGroup = false;
    // NAME
    $('#name').tooltip({
        title: "Please fill in your full name.",
        animation: true,
        trigger: "manual",
        placement: "top"

    }).focus(function () { // on mouse leave
        $('#name').tooltip('hide'); // leave the tooltip open
        if (red_shadow_on) {
            first_time_shadow = false;
            $('#name').css({
                'box-shadow': '0 0 5px red',
                'margin': '5px 1px 3px 0px',
                'border': '1px solid red'
            });
        } else if (first_time_shadow) {
            first_time_shadow = false;
            $('#name').css({
                'box-shadow': '0 0 5px rgba(81, 203, 238, 1)',
                'margin': '5px 1px 3px 0px',
                'border': '1px solid rgba(81, 203, 238, 1)'
            });
         
        } else {
            $('#name').css({
                'box-shadow': '0 0 5px green',
                'margin': '5px 1px 3px 0px',
                'border': '1px solid green'
            });
        }

    }).focusout(function () {
        if ($('#name').val().length < 5) {
            // insert validation here
            $('#name').tooltip('show'); // close the toolti
            $('#name').css({
                "border-color": "red",
                'background-image': 'none',
                'outline': 0,
                '-webkit-box-shadow': 'none',
                'box-shadow': 'none'
            });
            if (!danger_icon_added_for_nameFormGroup) {
                if (success_icon_added_for_nameFormGroup) {
                    $('#nameSuccessIcon').remove();
                }
                $('#nameFormGroup').append(danger_icon);
                danger_icon_added_for_nameFormGroup = true;
                success_icon_added_for_nameFormGroup = false;
            } 
            red_shadow_on = true;
        } else {
            red_shadow_on = false;
            $('#name').css({
                'background-image': 'none',
                'outline': 0,
                '-webkit-box-shadow': 'none',
                'box-shadow': 'none',
                'border-color': 'green'
            });
            if (!success_icon_added_for_nameFormGroup) {
                if (danger_icon_added_for_nameFormGroup) {
                    $('#nameDangerIcon').remove();
                }
                $('#nameFormGroup').append(success_icon);
                success_icon_added_for_nameFormGroup = true;
                danger_icon_added_for_nameFormGroup = false;
            }
        }
    });

   // SUBJECT
    $('#subject').tooltip({
        title: "Please fill in a subject.",
        animation: true,
        trigger: "manual",
        placement: "right"

    }).focus(function () { // on mouse leave
        $('#subject').tooltip('hide'); // leave the tooltip open
        if (red_shadow_on_subject) {
            first_time_shadow_subject = false;
            $('#subject').css({
                'box-shadow': '0 0 5px red',
                'margin': '5px 1px 3px 0px',
                'border': '1px solid red'
            });
        } else if (first_time_shadow_subject) {
            first_time_shadow_subject = false;
            $('#subject').css({
                'box-shadow': '0 0 5px rgba(81, 203, 238, 1)',
                'margin': '5px 1px 3px 0px',
                'border': '1px solid rgba(81, 203, 238, 1)'
            });

        } else {
            $('#subject').css({
                'box-shadow': '0 0 5px green',
                'margin': '5px 1px 3px 0px',
                'border': '1px solid green'
            });
        }

    }).focusout(function () {
        if ($('#subject').val().length < 4) {
            // insert validation here
            $('#subject').tooltip('show'); // close the toolti
            $('#subject').css({
                "border-color": "red",
                'background-image': 'none',
                'outline': 0,
                '-webkit-box-shadow': 'none',
                'box-shadow': 'none'
            });
            if (!danger_icon_added_for_subjectFormGroup) {
                if (success_icon_added_for_subjectFormGroup) {
                    $('#subjectSuccessIcon').remove();
                }
                $('#subjectFormGroup').append(danger_icon_subject);
                danger_icon_added_for_subjectFormGroup = true;
                success_icon_added_for_subjectFormGroup = false;
            }
            red_shadow_on_subject = true;
        } else {
            red_shadow_on_subject = false;
            $('#subject').css({
                'background-image': 'none',
                'outline': 0,
                '-webkit-box-shadow': 'none',
                'box-shadow': 'none',
                'border-color': 'green'
            });
            if (!success_icon_added_for_subjectFormGroup) {
                if (danger_icon_added_for_subjectFormGroup) {
                    $('#subjectDangerIcon').remove();
                }
                $('#subjectFormGroup').append(success_icon_subject);
                success_icon_added_for_subjectFormGroup = true;
                danger_icon_added_for_subjectFormGroup = false;
            }
        }
    });


  // EMAIL
    $('#email').tooltip({
        title: "Please enter a valid email.",
        animation: true,
        trigger: "manual",
        placement: "right"

    }).focus(function () { // on mouse leave
        $('#email').tooltip('hide'); // leave the tooltip open
        if (red_shadow_on_email) {
            first_time_shadow_email = false;
            $('#email').css({
                'box-shadow': '0 0 5px red',
                'margin': '5px 1px 3px 0px',
                'border': '1px solid red'
            });
        } else if (first_time_shadow_email) {
            first_time_shadow_email = false;
            $('#email').css({
                'box-shadow': '0 0 5px rgba(81, 203, 238, 1)',
                'margin': '5px 1px 3px 0px',
                'border': '1px solid rgba(81, 203, 238, 1)'
            });

        } else {
            $('#email').css({
                'box-shadow': '0 0 5px green',
                'margin': '5px 1px 3px 0px',
                'border': '1px solid green'
            });
        }

    }).focusout(function () {
        var email_string = $("#email").val();
        var valid = false;
        for (var i = 0; i < email_string.length; i++) {
            if (email_string[i] === '@') {
                valid = true;
                break;
            }
        }
        if (!valid) {
            // insert validation here
            $('#email').tooltip('show'); // close the toolti
            $('#email').css({
                "border-color": "red",
                'background-image': 'none',
                'outline': 0,
                '-webkit-box-shadow': 'none',
                'box-shadow': 'none'
            });
            if (!danger_icon_added_for_emailFormGroup) {
                if (success_icon_added_for_emailFormGroup) {
                    $('#emailSuccessIcon').remove();
                }
                $('#emailFormGroup').append(danger_icon_email);
                danger_icon_added_for_emailFormGroup = true;
                success_icon_added_for_emailFormGroup = false;
            }
            red_shadow_on_email = true;
        }
        else {
            $('#email').tooltip('hide');
            red_shadow_on_email = false;
            $('#email').css({
                'background-image': 'none',
                'outline': 0,
                '-webkit-box-shadow': 'none',
                'box-shadow': 'none',
                'border-color': 'green'
            });
            if (!success_icon_added_for_emailFormGroup) {
                if (danger_icon_added_for_emailFormGroup) {
                    $('#emailDangerIcon').remove();
                }
                $('#emailFormGroup').append(success_icon_email);
                success_icon_added_for_emailFormGroup = true;
                danger_icon_added_for_emailFormGroup = false;
            }
        }  
    });


    // Message
    $('#message').tooltip({
        title: "Please type in a message that is longer than 10 characters.",
        animation: true,
        trigger: "manual",
        placement: "bottom"
        
    }).focus(function () { // on mouse leave
        $('#message').tooltip('hide'); // leave the tooltip open
        if (red_shadow_on_message) {
            first_time_shadow_message = false;
            $('#message').css({
                'box-shadow': '0 0 5px red',
                'margin': '5px 1px 3px 0px',
                'border': '1px solid red'
            });
        } else if (first_time_shadow_message) {
            first_time_shadow_message = false;
            $('#message').css({
                'box-shadow': '0 0 5px rgba(81, 203, 238, 1)',
                'margin': '5px 1px 3px 0px',
                'border': '1px solid rgba(81, 203, 238, 1)'
            });

        } else {
            $('#message').css({
                'box-shadow': '0 0 5px green',
                'margin': '5px 1px 3px 0px',
                'border': '1px solid green'
            });
        }
        
    }).focusout(function () {
        if ($('#message').val().length < 10) {
            // insert validation here
            $('#message').tooltip('show'); // close the toolti
            $('#message').css({
                "border-color": "red",
                'background-image': 'none',
                'outline': 0,
                '-webkit-box-shadow': 'none',
                'box-shadow': 'none'
            });
            if (!danger_icon_added_for_messageFormGroup) {
                if (success_icon_added_for_messageFormGroup) {
                    $('#messageSuccessIcon').remove();
                }
                $('#messageFormGroup').append(danger_icon_message);
                danger_icon_added_for_messageFormGroup = true;
                success_icon_added_for_messageFormGroup = false;
            }
            red_shadow_on_message= true;
        } else {
            red_shadow_on_message = false;
            $('#message').css({
                'background-image': 'none',
                'outline': 0,
                '-webkit-box-shadow': 'none',
                'box-shadow': 'none',
                'border-color': 'green'
            });
            if (!success_icon_added_for_messageFormGroup) {
                if (danger_icon_added_for_messageFormGroup) {
                    $('#messageDangerIcon').remove();
                }
                $('#messageFormGroup').append(success_icon_message);
                success_icon_added_for_messageFormGroup = true;
                danger_icon_added_for_messageFormGroup = false;
            }
        }
    });


    // Send form
    $('#sendButton').on( "click", function () {
            $('#hiddenSendButton').trigger("click");
    });
    // END OF MODAL CONTACT EVENTS

    $('#downloadResumeButton').on("click", function () {
        $('#downloadResume a span').trigger("click");
    });



    // Card Flip
    $(".flip").hover(function () {
        $(this).find(".card").toggleClass("flipped");
        return false;
    });
});

