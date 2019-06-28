function applicationPreferences() {
}

applicationPreferences.prototype.get = function(key,success,fail) 
{
    cordova.exec(success,fail,"applicationPreferences","getSetting",[key]);
};

applicationPreferences.prototype.set = function(key,value,success,fail) 
{
    cordova.exec(success,fail,"applicationPreferences","setSetting",[key,value]);
};

cordova.addConstructor(function() 
{
	if(!window.plugins)
	{
		window.plugins = {};
	}
    window.plugins.applicationPreferences = new applicationPreferences();
});
