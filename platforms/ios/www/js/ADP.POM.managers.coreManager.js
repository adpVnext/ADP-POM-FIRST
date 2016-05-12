/*
 Editor : Essam Dahab
 Last Modification : 15/06/2015
 Version : 1.6.3
 */

var ADP = ADP || {};
ADP.POM = ADP.POM || {};
ADP.POM.managers = ADP.POM.managers || {};

function encodeMyHtml(str) {
    return String(str)
    .replace(/&/g, '&amp;')
    .replace(/"/g, '&quot;')
             .replace(/'/g, '&#39;')
                      .replace(/</g, '&lt;')
                      .replace(/>/g, '&gt;');
                      }
                      
                      (function(root) {
                       'use strict';
                       
                       //#region Constructor
                       
                       var CoreManager = function() {
                       // Private properies
                       // ex : this.creationValidationAlreadyLaunched = false;
                       };
                       //#endregion
                       
                       // #region Prototype
                       CoreManager.prototype = function(success, error) {
                       var _InitMenu = function() {
                       pomPlugin.InitMenu([], success, error);
                       },
                       _InitVPNManager = function(success, error) {
                       pomPlugin.InitVPNManager(success, error);
                       },
                       _GetFrameworkVersion = function(success, error) {
                       pomPlugin.GetFrameworkVersion(success, error);
                       },
                       _DisplayMenu = function(showState) {
                       pomPlugin.DisplayMenu([showState], success, error);
                       },
                       _CallApplication = function(url, success, error) {
                       pomPlugin.CallApplication([url], success, error);
                       },
                       
                       _Level1SecurityInfo = function(success, error) {
                       pomPlugin.Level1SecurityInfo(success, error);
                       },
                       
                       _OnLevel1SecurityInfoChange = function(callback) {
                       document.addEventListener('onLevel1SecurityInfoChanged', callback, false);
                       },
                       
                       _Level2SecurityInfo = function(success, error) {
                       pomPlugin.Level2SecurityInfo(success, error);
                       },
                       
                       _OnLevel2SecurityInfoChange = function(callback) {
                       document.addEventListener('onLevel2SecurityInfoChanged', callback, false);
                       },
                       
                       _RequestLevel2SignIn = function(success, error) {
                       pomPlugin.RequestLevel2SignIn(success, error);
                       },
                       _RequestLevel2SignOut = function(success, error) {
                       pomPlugin.RequestLevel2SignOut(success, error);
                       },
                       
                       _OnLevel2PreSignOut = function(callback) {
                       document.addEventListener('onLevel2PreSignOut', callback, false);
                       },
                       
                       _ForceRefreshSecurity = function(success, error) {
                       pomPlugin.ForceRefreshSecurity(success, error);
                       },
                       
                       _GetRawClaims = function(success, error) {
                       pomPlugin.GetRawClaims(success, error);
                       },
                       
                       _PostClaims = function(url, returnurl) {
                       
                       pomPlugin.GetRawClaims(function(data)
                                              {
                                              var token1 = "";
                                              var token2 = "";
                                              if (data.Token1)
                                              token1 = encodeMyHtml(data.Token1);
                                              if (data.Token2)
                                              token2 = encodeMyHtml(data.Token2);
                                              
                                              //Création dynamique du formulaire
                                              var form = document.createElement("form");
                                              form.setAttribute("method", "POST");
                                              form.setAttribute("action", url);
                                              
                                              var token1input = document.createElement("input");
                                              token1input.setAttribute("type", "hidden");
                                              token1input.setAttribute("name", "token1");
                                              token1input.setAttribute("value", token1);
                                              form.appendChild(token1input);
                                              
                                              var token2input = document.createElement("input");
                                              token2input.setAttribute("type", "hidden");
                                              token2input.setAttribute("name", "token2");
                                              token2input.setAttribute("value", token2);
                                              form.appendChild(token2input);
                                              
                                              var returnurlinput = document.createElement("input");
                                              returnurlinput.setAttribute("type", "hidden");
                                              returnurlinput.setAttribute("name", "returnurl");
                                              returnurlinput.setAttribute("value", returnurl);
                                              form.appendChild(returnurlinput);
                                              
                                              document.body.appendChild(form);
                                              form.submit();
                                              
                                              }, function(error)
                                              {
                                              
                                              })
                       },
                       
                       _AjaxPostClaims = function(url, callback) {
                       pomPlugin.GetRawClaims(function(data)
                                              {
                                              var xhr;
                                              if (window.XMLHttpRequest) {
                                              xhr = new XMLHttpRequest();
                                              }
                                              else if (window.ActiveXObject) {
                                              xhr = new ActiveXObject("Msxml2.XMLHTTP");
                                              }
                                              else {
                                              throw new Error("Ajax is not supported by this browser");
                                              }
                                              
                                              xhr.onreadystatechange = function () {
                                              if (xhr.readyState === 4) {
                                              if (xhr.status == 200 && xhr.status < 300) {
                                              callback(null);
                                              }
                                              else
                                              {
                                              callback("Error while posting claims "+ xhr.status);
                                              }
                                              }
                                              }
                                              
                                              var token1 = "";
                                              var token2 = "";
                                              if (data.Token1)
                                              token1 = encodeURIComponent(encodeMyHtml(data.Token1));
                                              if (data.Token2)
                                              token2 = encodeURIComponent(encodeMyHtml(data.Token2));
                                              var sendstr = "token1=" + token1 + "&token2=" + token2;
                                              xhr.open('POST', url);
                                              xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
                                              xhr.setRequestHeader("Content-Length", sendstr.length);
                                              xhr.send(sendstr);
                                              }, function(error)
                                              {
                                              callback("Error : Cannot get POM claims");
                                              });
                       },
                       
                       _GetApplicationList = function(success, error) {
                       pomPlugin.GetApplicationList(success, error);
                       },
                       
                       _GetUserThumbnailURL = function(success, error) {
                       pomPlugin.GetUserThumbnailURL(success, error);
                       },
                       
                       _GetUserThumbnailPicture = function(success, error) {
                       pomPlugin.GetUserThumbnailPicture(success, error);
                       },
                       
                       _IsTokenBlacklisted = function(success, error) {
                       pomPlugin.IsTokenBlacklisted(success, error);
                       },
                       
                       _OnMessageRaised = function(callback) {
                       document.addEventListener('onMessageRaised', callback, false);
                       };
                       
                       
                       return {
                       InitMenu : _InitMenu,
                       DisplayMenu : _DisplayMenu,
                       GetFrameworkVersion : _GetFrameworkVersion,
                       InitVPNManager : _InitVPNManager,
                       CallApplication : _CallApplication,
                       Level1SecurityInfo : _Level1SecurityInfo,
                       OnLevel1SecurityInfoChange : _OnLevel1SecurityInfoChange,
                       Level2SecurityInfo : _Level2SecurityInfo,
                       OnLevel2SecurityInfoChange : _OnLevel2SecurityInfoChange,
                       RequestLevel2SignIn : _RequestLevel2SignIn,
                       RequestLevel2SignOut : _RequestLevel2SignOut,
                       OnLevel2PreSignOut : _OnLevel2PreSignOut,
                       ForceRefreshSecurity : _ForceRefreshSecurity,
                       GetRawClaims : _GetRawClaims,
                       AjaxPostClaims : _AjaxPostClaims,
                       PostClaims : _PostClaims,
                       GetApplicationList : _GetApplicationList,
                       GetUserThumbnailURL : _GetUserThumbnailURL,
                       GetUserThumbnailPicture : _GetUserThumbnailPicture,
                       IsTokenBlacklisted : _IsTokenBlacklisted,
                       OnMessageRaised : _OnMessageRaised
                       };
                       
                       }();
                       
                       root.coreManager = new CoreManager();
                       
                       }(ADP.POM.managers));