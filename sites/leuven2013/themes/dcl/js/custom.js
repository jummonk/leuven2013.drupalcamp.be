(function($) {
  Drupal.behaviors.theming = {
    attach: function(context, settings) {

      // primary menu responsive
      var priMenu = $('#header-top-inner #block-menu-block-1');
      var priSubMenu = $('#header-top-inner #block-menu-block-1 ul li.expanded ul');
      priSubMenu.hide();
      $('<div id="menubutton"></div>').insertBefore('#header-top-inner');
      $('<div id="submenubutton"></div>').insertBefore(priSubMenu);
      $('#menubutton').click(function(){
        priMenu.slideToggle('fast');
        $(this).toggleClass('open');
      });
      $('li.expanded #submenubutton').each(function(){
        $(this).click(function(){
          $(this).next().slideToggle('fast');
          $(this).toggleClass('open');
        });
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

      // counter
      $('#cntdwn').appendTo('#block-block-8 #counter');

      // front blocks link
      $('#header-bottom-left').click(function(){
        window.location = "/program/sessions";
      });
      $('#header-bottom-middle').click(function(){
        window.location = "/community";
      });
      $('#header-bottom-right').click(function(){
        window.location = "/community/attendees";
      });

      // program views-rows equal height
      $('.page-program .view-sessions .views-row').equalHeights();

      // program feed icon
      $('.page-program #main-wrapper .feed-icon').appendTo('.page-program #main-wrapper .view-filters');

      // program filter button
      var filter = $('.page-program #main-wrapper .view-filters');
      filter.hide();
      $('<div id="filterbox">filter <span id="filterbutton"></span></div>').insertBefore(filter);
      $('span#filterbutton').click(function(){
        filter.slideToggle('fast');
        $(this).toggleClass('open');
      });

    }
  };
})(jQuery);