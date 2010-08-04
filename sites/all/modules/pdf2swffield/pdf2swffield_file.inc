<?php
// $Id$

/**
 * @file
 * hook_file and pdf2swffield file functions.
 */

/**
 * Implementation of hook_file_insert().
 */
function pdf2swffield_file_insert($file) {
	// doc root
	$doc_root = getcwd().'/';
	  
	$command = "%pdf2swf_path %parameters %input -o %output";

	$output = $doc_root . $file->filepath . ".swf";
	$input = $doc_root . $file->filepath;
	$viewer = "--viewer " . $doc_root . drupal_get_path("module", "pdf2swffield") . "/testviewer13.swf";
	$pdf2swf_path = $file->field["widget"]["path_to_pdf2swf"];	
	$pdf2swf_commanfline = $file->field["widget"]["pdf2swf_commandline"];
	
 	$command = str_replace("%output", $output, $command);
 	$command = str_replace("%input", $input, $command);
 	$command = str_replace("%pdf2swf_path", $pdf2swf_path, $command);
 	$command = str_replace("%parameters", $pdf2swf_commanfline, $command);
 	$command = str_replace("%viewer", $viewer, $command);  
  	
 	exec($command, $output);
 	drupal_set_message($command);
	drupal_set_message("pdf2swf output:");
  pdf2swffield_fe($output);
}

/**
 * Implementation of hook_file_delete().
 *
 * Delete swf file when pdf was deleted
 */
function pdf2swffield_file_delete($file) {
	// doc root
	$ls = substr($_SERVER["DOCUMENT_ROOT"], -1);
	if($ls == "/" || $ls == "\\") {
		$doc_root = substr($_SERVER["DOCUMENT_ROOT"], 0, strlen($_SERVER["DOCUMENT_ROOT"]) - 1);
	} else {
		$doc_root = $_SERVER["DOCUMENT_ROOT"];
	}
	$doc_root .= base_path();

	// delete swf and pdf files from server
  if($file->filepath && file_exists($doc_root . $file->filepath)) {
		if(unlink($doc_root . $file->filepath)) {
			drupal_set_message($doc_root . $file->filepath . " removed");
		}
    }
    if(file_exists($doc_root . $file->filepath . '.swf')) {
    	if(unlink($doc_root . $file->filepath . '.swf')) {
			drupal_set_message($doc_root . $file->filepath . '.swf' . " removed");
		}
	}
}

/**
 * Simple utility function to check if a file is an pdf-document.
 */
function pdf2swffield_file_is_pdf($file) {
  $file = (object)$file;
  return in_array($file->filemime, array('application/pdf'));
}

function pdf2swffield_fe($data, $tab = 0) {
	$t = "";
	for($i = 0; $i <= $tab; $i++) {
		$t .= "--";
	}
	
	if($tab == 0) {
		drupal_set_message(" ============== ");
	}
	
	foreach($data as $k => $v) {
		if(!is_array($v)) {
			drupal_set_message($t . $k . " => " . $v);
		} else if($tab < 20){
			pdf2swffield_fe($v, ($tab+1));
		}
	}
	
	if($tab == 0) {
		drupal_set_message(" ============== ");
	} else {
		drupal_set_message("--");
	}
}
