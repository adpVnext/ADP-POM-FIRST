/*
 Editor : Essam Dahab
 Last Modification : 03/04/2015
 Version : 1.6.3
 */

var ADP = ADP || {};
ADP.POM = ADP.POM || {};
ADP.POM.managers = ADP.POM.managers || {};


(function(root) {
	'use strict';



	//#region Constructor

	var ScanManager = function() {
		// Private properies
		// ex : this.creationValidationAlreadyLaunched = false;
	};

	//#endregion

	// #region Prototype
	ScanManager.prototype = function() {
		var _LaunchScan = function(success, error) {
            pomPlugin.LaunchScan(success, error);
		},
 
		_LaunchTicketScan = function(success, error) {
            pomPlugin.LaunchTicketScan(success, error);
        };
		
		return {
			LaunchScan : _LaunchScan,
			LaunchTicketScan : _LaunchTicketScan
		};
				
	}();

	root.scanManager = new ScanManager();

}(ADP.POM.managers));