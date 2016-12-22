cordova.define("fr.aeroportsdeparis.cordova.pom.POM", function(require, exports, module) {
/*
 Editor : Essam Dahab
 Last Modification : 15/06/2015
 Version : 1.7.0
 */


var argscheck = require('cordova/argscheck'),
channel = require('cordova/channel'),
utils = require('cordova/utils'),
exec = require('cordova/exec'),
cordova = require('cordova');

function POMPlugin() {
    
}

POMPlugin.prototype.GetFrameworkVersion = function(successCallback, errorCallback) {
    exec(successCallback, errorCallback, "POM", "GetFrameworkVersion", []);
};

POMPlugin.prototype.InitMenu = function(options, successCallback, errorCallback) {
    //argscheck.checkArgs('fF', 'POMPlugin.InitMenu', arguments);
    exec(successCallback, errorCallback, "POM", "InitMenu", options);
};

POMPlugin.prototype.InitVPNManager = function(options, successCallback, errorCallback) {
    //argscheck.checkArgs('fF', 'POMPlugin.InitVPNManager', arguments);
    exec(successCallback, errorCallback, "POM", "InitVPNManager", options);
};

POMPlugin.prototype.DisplayMenu = function(options, successCallback, errorCallback) {
    //argscheck.checkArgs('fF', 'POMPlugin.DisplayMenu', arguments);
    exec(successCallback, errorCallback, "POM", "DisplayMenu", options);
};

POMPlugin.prototype.Level1SecurityInfo = function(successCallback, errorCallback) {
    //argscheck.checkArgs('fF', 'POMPlugin.Level1SecurityInfo', arguments);
    exec(successCallback, errorCallback, "POM", "Level1SecurityInfo", []);
};

POMPlugin.prototype.Level2SecurityInfo = function(successCallback, errorCallback) {
    //argscheck.checkArgs('fF', 'POMPlugin.Level2SecurityInfo', arguments);
    exec(successCallback, errorCallback, "POM", "Level2SecurityInfo", []);
};

POMPlugin.prototype.CallApplication = function(options, successCallback, errorCallback) {
    //argscheck.checkArgs('fF', 'POMPlugin.CallApplication', arguments);
    exec(successCallback, errorCallback, "POM", "CallApplication", options);
};

POMPlugin.prototype.RequestLevel2SignIn = function(successCallback, errorCallback) {
    //argscheck.checkArgs('fF', 'POMPlugin.RequestLevel2SignIn', arguments);
    exec(successCallback, errorCallback, "POM", "RequestLevel2SignIn", []);
};

POMPlugin.prototype.RequestLevel2SignOut = function(successCallback, errorCallback) {
    //argscheck.checkArgs('fF', 'POMPlugin.RequestLevel2SignOut', arguments);
    exec(successCallback, errorCallback, "POM", "RequestLevel2SignOut", []);
};

POMPlugin.prototype.ForceRefreshSecurity = function(successCallback, errorCallback) {
    //argscheck.checkArgs('fF', 'POMPlugin.ForceRefreshSecurity', arguments);
    exec(successCallback, errorCallback, "POM", "ForceRefreshSecurity", []);
};

POMPlugin.prototype.GetRawClaims = function(successCallback, errorCallback) {
    //argscheck.checkArgs('fF', 'POMPlugin.GetRawClaims', arguments);
    exec(successCallback, errorCallback, "POM", "GetRawClaims", []);
};

POMPlugin.prototype.GetApplicationList = function(successCallback, errorCallback) {
    //argscheck.checkArgs('fF', 'POMPlugin.GetApplicationList', arguments);
    exec(successCallback, errorCallback, "POM", "GetApplicationList", []);
};

POMPlugin.prototype.GetUserThumbnailURL = function(successCallback, errorCallback) {
    //argscheck.checkArgs('fF', 'POMPlugin.GetUserThumbnailURL', arguments);
    exec(successCallback, errorCallback, "POM", "GetUserThumbnailURL", []);
};

POMPlugin.prototype.GetUserThumbnailPicture = function(successCallback, errorCallback) {
    //argscheck.checkArgs('fF', 'POMPlugin.GetUserThumbnailPicture', arguments);
    exec(successCallback, errorCallback, "POM", "GetUserThumbnailPicture", []);
};
               
POMPlugin.prototype.IsTokenBlacklisted = function(successCallback, errorCallback) {
//argscheck.checkArgs('fF', 'POMPlugin.IsTokenBlacklisted', arguments);
exec(successCallback, errorCallback, "POM", "IsTokenBlacklisted", []);
};

POMPlugin.prototype.DownloadFile = function(options, successCallback, errorCallback) {
    //argscheck.checkArgs('fF', 'POMPlugin.DownloadFile', arguments);
    exec(successCallback, errorCallback, "POM", "DownloadFile", options);
};

POMPlugin.prototype.ViewFile = function(options, successCallback, errorCallback) {
    //argscheck.checkArgs('fF', 'POMPlugin.ViewFile', arguments);
    exec(successCallback, errorCallback, "POM", "ViewFile", options);
};

POMPlugin.prototype.GetLibraryList = function(successCallback, errorCallback) {
    //argscheck.checkArgs('fF', 'POMPlugin.GetLibraryList', arguments);
    exec(successCallback, errorCallback, "POM", "GetLibraryList", []);
};

POMPlugin.prototype.LaunchScan = function(successCallback, errorCallback) {
    //argscheck.checkArgs('fF', 'POMPlugin.LaunchScan', arguments);
    exec(successCallback, errorCallback, "POM", "LaunchScan", []);
};

POMPlugin.prototype.LaunchTicketScan = function(successCallback, errorCallback) {
    //argscheck.checkArgs('fF', 'POMPlugin.LaunchTicketScan', arguments);
    exec(successCallback, errorCallback, "POM", "LaunchTicketScan", []);
};


module.exports = new POMPlugin();
});
