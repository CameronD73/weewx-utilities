## current module for weewx skins
## Copyright Tom Keffer, Matthew Wall
## See LICENSE.txt for your rights
#errorCatcher Echo
#encoding UTF-8

<div id='current_widget' class="widget">
  <div class="widget_title">
    $gettext("Current Conditions")
    <a class="widget_control"
      onclick="toggle_widget('current')">&diams;</a>
  </div>

  <div class="widget_contents">
  <table>
    <tbody>

      <tr>
        <td class="label">Temp up/downstairs</td>
        <td class="data">$latest($data_binding='ecowitt_binding').inTemp_gw , $latest($data_binding='ecowitt_binding').inTemp_wh31_1</td>
      </tr>
      
#set $observations = $to_list($DisplayOptions.get('observations_current', ['outTemp', 'barometer']))

#for $x in $observations
  #if $getVar('year.%s.has_data' % $x)
    #if $x == 'barometer'
      <tr>
        <td class="label">$obs.label.barometer</td>
        <td class="data">$current.barometer ($trend.barometer.formatted)</td>
      </tr>
    #elif $x == 'windSpeed'
      <tr>
        <td class="label">$obs.label.wind</td>
        <td class="data">$current.windSpeed $current.windDir.ordinal_compass ($current.windDir)</td>
      </tr>
    #elif $x == 'rain'
      <tr>
        <td class="label">$gettext("Rain Today")</td>
        <td class="data">$day.rain.sum</td>
      </tr>
    #else
      <tr>
        <td class="label">$obs.label[$x]</td>
        <td class="data">$getVar('current.' + $x)</td>
      </tr>
    #end if
  #end if
#end for

## these are just hard-coded in, because they are for local use only
      <tr>
        <td class="label">PM2.5, PM10</td>
        <td><span class="data">$latest($data_binding='ecowitt_binding').pm2_5_wh45</span> ;
            <span class="data">$latest($data_binding='ecowitt_binding').pm10_wh45</span></td>
      </tr>
      <tr>
        <td class="label">CO<sub>2</sub></td>
        <td class="data">$latest($data_binding='ecowitt_binding').co2</td>
      </tr>
      <tr>
        <td class="label">Hum. up/down</td>
        <td class="data">$latest($data_binding='ecowitt_binding').inHumidity_gw , $latest($data_binding='ecowitt_binding').inHumidity_wh31_1</td>
      </tr>

    </tbody>
  </table>
  </div>

</div>
