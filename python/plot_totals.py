import sys

import pandas as pd

import plotly.graph_objects as go
from plotly.colors import DEFAULT_PLOTLY_COLORS

files = sys.argv[1:]

df = None

total_cols = ['life', 'poison', 'squirrel', 'cat', 'dog', 'energy', 'spirit', 'construct', 'knight', 'goblin']

columns = ['time'] + total_cols

for file in files:
    client_id = file.split('_')[-1][:-4]
    if df is None:
        df = pd.read_csv(file, names=columns)
        df['client'] = client_id
    else:
        df_tmp = pd.read_csv(file, names=columns)
        df_tmp['client'] = client_id
        df = pd.concat([df, df_tmp])

df['time'] -= df['time'].min()


# for total in total_cols:

#     fig = px.line(df, x='time', y=total_cols, color='client', markers=True)
# fig.show()


# title = 'Main Source for News'
# labels = ['Television', 'Newspaper', 'Internet', 'Radio']
# colors = ['rgb(67,67,67)', 'rgb(115,115,115)', 'rgb(49,130,189)', 'rgb(189,189,189)']

fig = go.Figure()

clients = df['client'].unique()

last_time = df['time'].max()

STYLES = [
    {},
    {'dash': 'dash'},
    {'dash': 'dot'},
    {'mode': 'lines+markers'},
]


for client_idx, client in enumerate(clients):
    client_df = df[df['client'] == client]
    if client_df['time'].max() < last_time:
        row = client_df.iloc[-1].copy()
        row['time'] = last_time
        client_df = client_df.append(row)
    client_style = STYLES[client_idx]
    for color_idx, total in enumerate(total_cols):
        if df[total].max() == 0:
            continue
        line_style = dict(client_style)
        line_style['color'] = DEFAULT_PLOTLY_COLORS[color_idx]
        fig.add_trace(go.Scatter(x=client_df['time'], y=client_df[total], mode='lines',
            name=client + ' ' + total,
            line=line_style
        ))


# fig.update_layout(
#     xaxis=dict(
#         showline=True,
#         showgrid=False,
#         showticklabels=True,
#         linecolor='rgb(204, 204, 204)',
#         linewidth=2,
#         ticks='outside',
#         tickfont=dict(
#             family='Arial',
#             size=12,
#             color='rgb(82, 82, 82)',
#         ),
#     ),
#     yaxis=dict(
#         showgrid=False,
#         zeroline=False,
#         showline=False,
#         showticklabels=False,
#     ),
#     autosize=False,
#     margin=dict(
#         autoexpand=False,
#         l=100,
#         r=20,
#         t=110,
#     ),
#     showlegend=False,
#     plot_bgcolor='white'
# )

# annotations = []

# # Adding labels
# for y_trace, label, color in zip(y_data, labels, colors):
#     # labeling the left_side of the plot
#     annotations.append(dict(xref='paper', x=0.05, y=y_trace[0],
#                                   xanchor='right', yanchor='middle',
#                                   text=label + ' {}%'.format(y_trace[0]),
#                                   font=dict(family='Arial',
#                                             size=16),
#                                   showarrow=False))
#     # labeling the right_side of the plot
#     annotations.append(dict(xref='paper', x=0.95, y=y_trace[11],
#                                   xanchor='left', yanchor='middle',
#                                   text='{}%'.format(y_trace[11]),
#                                   font=dict(family='Arial',
#                                             size=16),
#                                   showarrow=False))
# # Title
# annotations.append(dict(xref='paper', yref='paper', x=0.0, y=1.05,
#                               xanchor='left', yanchor='bottom',
#                               text='Main Source for News',
#                               font=dict(family='Arial',
#                                         size=30,
#                                         color='rgb(37,37,37)'),
#                               showarrow=False))
# # Source
# annotations.append(dict(xref='paper', yref='paper', x=0.5, y=-0.1,
#                               xanchor='center', yanchor='top',
#                               text='Source: PewResearch Center & ' +
#                                    'Storytelling with data',
#                               font=dict(family='Arial',
#                                         size=12,
#                                         color='rgb(150,150,150)'),
#                               showarrow=False))

# fig.update_layout(annotations=annotations)

fig.show()