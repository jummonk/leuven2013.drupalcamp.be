(function($) {
  Drupal.behaviors.theming = {
    attach: function(context, settings) {

      // primary menu
      var priMenu = $('#header-top-inner #block-superfish-1');
      $('<div id="menubutton"></div>').insertBefore('#header-top-inner');
      $('#menubutton').click(function(){
        priMenu.slideToggle('fast');
        $(this).toggleClass('open');
      });

      // secondary menu
      var secMenu = $('#header-top-inner #navigation ul');
      secMenu.hide();
      $('<div id="navbutton"></div>').insertBefore(secMenu);
      $('#navbutton').click(function(){
      	secMenu.slideToggle('fast');
      	$(this).toggleClass('open');
      });

      // not front header click to frontpage
      $('body.not-front #header #header-middle').click(function(){
        window.location = "/";
      });

    }
  };
})(jQuery);