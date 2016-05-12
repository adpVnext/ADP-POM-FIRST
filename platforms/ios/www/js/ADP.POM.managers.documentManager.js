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

	var DocumentManager = function() {
		// Private properies
		// ex : this.creationValidationAlreadyLaunched = false;
	};

	//#endregion

	// #region Prototype
	DocumentManager.prototype = function() {
		var _GetLibraryList = function(success, error) {
            pomPlugin.GetLibraryList(success, error);
		},
 
		_ViewFile = function(url, success, error) {
            pomPlugin.ViewFile([url],success, error);
		},
 
        _DownloadFile = function(url, success, error) {
            pomPlugin.DownloadFile([url],success, error);
 
		}
 
		return {
			GetLibraryList : _GetLibraryList,
			ViewFile : _ViewFile,
			DownloadFile : _DownloadFile
		};
				
	}();

	root.documentManager = new DocumentManager();

}(ADP.POM.managers));