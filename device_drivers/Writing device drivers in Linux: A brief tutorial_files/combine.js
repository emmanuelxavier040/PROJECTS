jQuery('html').removeClass('no-js').addClass('js');if(navigator.appVersion.indexOf("Mac")!=-1)
jQuery('html').addClass('osx');jQuery(document).ready(function($){(function(){$(window).load(function(){$('a[rel=external]').attr('target','_blank');});})();(function(){$('body').tooltip({delay:{show:300,hide:0},selector:'[data-toggle=tooltip]:not([disabled])'});})();(function(){$('<a id="back-to-the-top"></a>').appendTo($('body'));$(window).scroll(function(){if($(this).scrollTop()!=0){$('#back-to-the-top').fadeIn();}else{$('#back-to-the-top').fadeOut();}});$('#back-to-the-top').click(function(){$('body,html').animate({scrollTop:0},800);});})();(function(){$(window).load(function(){var $container=$('#portfolio-items');function filter_projects(tag)
{$container.isotope({filter:tag});$('li.active').removeClass('active');$('#portfolio-filter').find("[data-filter='"+ tag+"']").parent().addClass('active');if(tag!='*')
window.location.hash=tag.replace('.','');if(tag=='*')
window.location.hash='';}
if($container.length){$('.project').each(function(){$this=$(this);var tags=$this.data('tags');if(tags){var classes=tags.split(',');for(var i=classes.length- 1;i>=0;i--){$this.addClass(classes[i]);};}})
$container.isotope({itemSelector:'.project',layoutMode:'fitRows'});$('#portfolio-filter li a').click(function(){var selector=$(this).attr('data-filter');filter_projects(selector);return false;});if(window.location.hash!='')
{filter_projects('.'+ window.location.hash.replace('#',''));}}})})();$(window).load(function(){});});