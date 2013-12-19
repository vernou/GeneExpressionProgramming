// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This function is called by common.js when the NaCl module is
// loaded.
function moduleDidLoad() {
  // Once we load, hide the plugin. In this example, we don't display anything
  // in the plugin, so it is fine to hide it.
  common.hideModule();

  // After the NaCl module has loaded, common.naclModule is a reference to the
  // NaCl module's <embed> element.
  //
  // postMessage sends a message to it.
  common.naclModule.postMessage('lProgram is ready');
}

// This function is called by common.js when a message is received from the
// NaCl module.
function handleMessage(message) {
    var spanEL = document.createElement('div');
    var logEl = document.getElementById('log');
    logEl.appendChild(spanEL);
    spanEL.textContent += message.data;
}

// Called by the common.js module.
function attachListeners() {
  function addEventListenerToButton(parentId, func) {
    document.querySelector('#' + parentId + ' button')
        .addEventListener('click', func);
  }

  addEventListenerToButton('sendData', sendData);
  addEventListenerToButton('run', run);
}

function sendData() {
  if (common.naclModule) {
    var csvData = "d"+document.querySelector('#sendData textarea').value;
	common.naclModule.postMessage(csvData);
  }
}

function run() {
    if (common.naclModule) {
        var csvData = "r";
        common.naclModule.postMessage(csvData);
    }
}