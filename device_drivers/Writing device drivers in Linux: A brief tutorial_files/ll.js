$ezJQuery.ajaxSetup({cache:true});ez_queue.push({method:function()
{$ezJQuery.getScript('//connect.facebook.net/en_US/all.js#xfbml=1',function(){FB.init({status:true,cookie:true,xfbml:true});FB.Event.subscribe('edge.create',function(href,widget){if(widget.dom.id!='')
{var button=widget.dom.id.substring(0,widget.dom.id.indexOf("-"));var domain_id=widget.dom.id.substring(widget.dom.id.indexOf("-")+1);record_social_share('fb_like_'+button,domain_id);}});});!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");(function(){var po=document.createElement('script');po.type='text/javascript';po.async=true;po.src='https://apis.google.com/js/plusone.js';var s=document.getElementsByTagName('script')[0];s.parentNode.insertBefore(po,s);})();},priority:10});function fbs_click(_image,domain_id){var leftPosition=(window.screen.width/2)-300;var topPosition=(window.screen.height/2)-220;var windowFeatures="status=no,height=336,width=526,resizable=yes,left="+leftPosition+",top="+topPosition+",screenX="+leftPosition+",screenY="+topPosition+",toolbar=no,menubar=no,scrollbars=no,location=no,directories=no";_image=_image.replace("http://cdn.","http://");var domain=document.URL.replace('http://','').replace('https://','').split(/[/?#]/)[0];var finalurl='http://'+domain+'/l/fburl'+document.URL;window.open('//www.facebook.com/sharer.php?s=100&p[title]='+document.title+'&p[url]='+finalurl+'&p[images][0]='+encodeURI(_image)+'&p[summary]=','sharer',windowFeatures);record_social_share('fb_share',domain_id);return false;}
function pin_click(_image,_description,domain_id){var leftPosition=(window.screen.width/2)-300;var topPosition=(window.screen.height/2)-220;var windowFeatures="status=no,height=336,width=560,resizable=yes,left="+leftPosition+",top="+topPosition+",screenX="+leftPosition+",screenY="+topPosition+",toolbar=no,menubar=no,scrollbars=no,location=no,directories=no";_image=_image.replace("http://cdn.","http://");window.open('//pinterest.com/pin/create/button/?url='+encodeURIComponent(document.URL)+'&media='+encodeURI(_image)+'&description='+encodeURI(_description),'signin',windowFeatures);record_social_share('pin',domain_id);return false;}
function record_social_share(soc_type,domain_id){var url="http://utilcave.com/social/social.ajax.php?soctype={soctype}&did={did}&url={url}&callback=?";url=url.replace(/{soctype}/,soc_type).replace(/{url}/,encodeURI(window.location.href)).replace(/{did}/,domain_id);if(typeof $ezJQuery!='undefined')
{$ezJQuery.getJSON(url);}}
var _qevents=_qevents||[];ez_queue.push({method:function()
{_qevents.push({qacct:"p-31iz6hfFutd16"});(function(){var elem=document.createElement('script');elem.src=(document.location.protocol=="https:"?"https://secure":"http://edge")+".quantserve.com/quant.js";elem.async=true;elem.type="text/javascript";var scpt=document.getElementsByTagName('script')[0];scpt.parentNode.insertBefore(elem,scpt);})();},priority:10});