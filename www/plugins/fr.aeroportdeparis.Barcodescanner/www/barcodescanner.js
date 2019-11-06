cordova.define("fr.aeroportdeparis.Barcodescanner.BARCOD", function(require, exports, module) {

var exec = require('cordova/exec'),
cordova = require('cordova');

var BarcodeScanner = function () {};


//-------------------------------------------------------------------
BarcodeScanner.prototype.scan = function (successCallback, errorCallback) {
    if (errorCallback == null) {
        errorCallback = function () {
        }
    }
    
    if (typeof errorCallback != "function") {
        console.log("le Scan a échoué. Le 'errorCallback' doit etre une fonction");
        return
    }
    
    if (typeof successCallback != "function") {
        console.log("le Scan a échoué. Le 'success callback' doit etre une function");
        return
    }
    
    cordova.exec(successCallback, errorCallback, 'BarcodeScanner', 'scan', []);
};

//-------------------------------------------------------------------

var barcodeScanner = new BarcodeScanner();
module.exports = barcodeScanner;


});
